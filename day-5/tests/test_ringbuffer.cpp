#include <catch2/catch_test_macros.hpp>
#include "../include/RingBuffer.h"

// --- push / pop basics ---

TEST_CASE("isEmpty on new buffer") {
    RingBuffer<int, 4> buf;
    REQUIRE(buf.isEmpty() == true);
    REQUIRE(buf.isFull() == false);
    REQUIRE(buf.size() == 0);
}

TEST_CASE("push increases size") {
    RingBuffer<int, 4> buf;
    buf.push(10);
    buf.push(20);
    REQUIRE(buf.size() == 2);
}

TEST_CASE("push returns false when full") {
    RingBuffer<int, 3> buf;
    REQUIRE(buf.push(1) == true);
    REQUIRE(buf.push(2) == true);
    REQUIRE(buf.push(3) == true);
    REQUIRE(buf.push(4) == false);  // full
    REQUIRE(buf.size() == 3);
}

TEST_CASE("pop returns values in FIFO order") {
    RingBuffer<int, 4> buf;
    buf.push(1);
    buf.push(2);
    buf.push(3);
    REQUIRE(buf.pop() == 1);
    REQUIRE(buf.pop() == 2);
    REQUIRE(buf.pop() == 3);
}

TEST_CASE("pop returns nullopt when empty") {
    RingBuffer<int, 4> buf;
    REQUIRE(buf.pop() == std::nullopt);
}

// --- peek ---

TEST_CASE("peek returns front without removing") {
    RingBuffer<int, 4> buf;
    buf.push(42);
    REQUIRE(buf.peek() == 42);
    REQUIRE(buf.size() == 1);  // still there
}

TEST_CASE("peek returns nullopt when empty") {
    RingBuffer<int, 4> buf;
    REQUIRE(buf.peek() == std::nullopt);
}

// --- wrap-around (the tricky circular part) ---

TEST_CASE("buffer wraps around correctly") {
    RingBuffer<int, 3> buf;
    buf.push(1);
    buf.push(2);
    buf.push(3);
    buf.pop();   // remove 1, head moves
    buf.push(4); // should wrap around to index 0
    REQUIRE(buf.pop() == 2);
    REQUIRE(buf.pop() == 3);
    REQUIRE(buf.pop() == 4);
}

// --- works with float and custom struct ---

TEST_CASE("works with float") {
    RingBuffer<float, 4> buf;
    buf.push(1.5f);
    buf.push(2.5f);
    REQUIRE(buf.pop() == 1.5f);
}

TEST_CASE("works with custom struct") {
    struct SensorReading { float value; int timestamp; };
    RingBuffer<SensorReading, 4> buf;
    buf.push({3.14f, 100});
    const auto val = buf.pop();
    REQUIRE(val.has_value());
    REQUIRE(val->value == 3.14f);
    REQUIRE(val->timestamp == 100);
}