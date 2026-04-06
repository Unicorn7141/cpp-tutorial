#include <fmt/core.h>
#include "RingBuffer.h"

int main() {
    RingBuffer<float, 5> buf;
    bool ok;
    // Push some values
    fmt::print("--- Pushing values ---\n");
    for (float val : {1.1f, 2.2f, 3.3f, 4.4f, 5.5f}) {
        ok = buf.push(val);
        fmt::print("push({:.1f}) -> {}\n", val, ok ? "ok" : "full");
    }

    // Try pushing when full
    fmt::print("\n--- Pushing to a full buffer ---\n");
    ok = buf.push(6.6f);
    fmt::print("push(6.6) -> {}\n", ok ? "ok" : "full");

    // Peek at front
    fmt::print("\n--- Peek ---\n");
    if (auto val = buf.peek()) {
        fmt::print("peek() -> {:.1f}\n", *val);
    }

    // Pop all values
    fmt::print("\n--- Popping all values ---\n");
    while (auto val = buf.pop()) {
        fmt::print("pop() -> {:.1f}\n", *val);
    }

    // Pop when empty
    fmt::print("\n--- Popping empty buffer ---\n");
    const auto empty = buf.pop();
    fmt::print("pop() -> {}\n", empty.has_value() ? "got value" : "nullopt");

    // Wrap-around demo
    fmt::print("\n--- Wrap-around demo ---\n");
    buf.push(10.0f);
    buf.push(20.0f);
    buf.push(30.0f);
    buf.pop();  // remove 10
    buf.pop();  // remove 20
    buf.push(40.0f);
    buf.push(50.0f);
    fmt::print("After wrap-around, popping: ");
    while (auto val = buf.pop()) {
        fmt::print("{:.1f} ", *val);
    }
    fmt::print("\n");

    return 0;
}