#pragma once
#include <algorithm>
#include <any>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

class EventBus {
public:
    using ListenerID = std::size_t;
    using Callback = std::function<void(std::any)>;

    template<typename T>
    ListenerID subscribe(const std::string &eventName, std::function<void(T)> cb)  {

        ListenerID id = next_id_++;

        Callback wrapper = [eventName, cb](std::any data) {
            try {
                cb(std::any_cast<T>(data));
            } catch (const std::bad_any_cast &) {
                std::cerr << "Type mismatch on event: " << eventName << '\n';
            }
        };

        listeners_[eventName].emplace_back(id, std::move(wrapper));
        return id;
    }

    template<typename T>
    void emit(const std::string &eventName, T value) {
        const auto it = listeners_.find(eventName);
        if (it == listeners_.end()) return;

        const std::any data = value;
        for (auto &fn: it->second | std::views::values) {
            fn(data);
        }
    }

    void unsubscribe(const std::string &eventName, ListenerID id) {
        auto it = listeners_.find(eventName);
        if (it == listeners_.end()) return;

        auto &vec = it->second;
        std::erase_if(vec,
                      [id](const auto &entry) { return entry.first == id; });
    }

    uint16_t countListeners(const std::string &name) {
        return listeners_[name].size();
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<ListenerID, Callback> > > listeners_;
    ListenerID next_id_ = 0;
};
