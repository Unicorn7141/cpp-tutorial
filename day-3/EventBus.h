//
// Created by harel on 04/04/2026.
//

#pragma once
#include <any>
#include <string>
#include <functional>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <iostream>

class EventBus {
public:

    // Subscribe
    template <typename T>
    void subscribe(const std::string &name, const std::function<void(T)> cb) { // cb = callback
        listeners_[name].push_back([cb](std::any data) {
            cb(std::any_cast<T>(data));
        });

        std::cout << "New listener added to: " << name << "\n";
    }

    // Emit
    template <typename T>
    void emit(const std::string &name, T data) {
        for (auto &fn : listeners_[name]) fn(data);
    }

    // Unsubscribe
    void unsubscribe(const std::string &name) {
        listeners_.erase(name);
        std::cout << "Deleted " << name << "\n";
    }

private:
    std::unordered_map<std::string, std::vector<std::function<void(std::any)>>> listeners_;
};