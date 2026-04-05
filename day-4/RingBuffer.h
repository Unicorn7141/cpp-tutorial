//
// Created by harel on 05/04/2026.
//

#pragma once
#include <array>
#include <cstddef>
#include <optional>

template <typename T, std::size_t N>
requires std::is_trivially_copyable_v<T>

class RingBuffer {
    std::array<T, N> buf;
    mutable std::size_t head = 0;
    std::size_t tail = 0;
    std::size_t count = 0;

public:
    bool push(const T &val) {
        if (isFull()) return false;
        buf[tail] = val;
        tail = (tail + 1) % N;
        ++count;
        return true;
    }

    std::optional<T> pop() {
        if (isEmpty()) return std::nullopt;
        T value = buf[head];
        head = (head + 1) % N;
       --count;
        return value;
    }

    std::optional<T> peek() const {
        if (isEmpty()) return std::nullopt;
        return buf[head];
    }

    bool isFull() const { return count == N; }
    bool isEmpty() const { return count == 0; }
    std::size_t size() const { return count; }
    void print() {
        std::size_t i;
        for (i = 0; i < count-1; ++i) {
            std::cout << "[" << buf[i] << "] -> ";
        }
        std::cout << "[" << buf[i] << "]\n";
    }
};
