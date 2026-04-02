# C++ Learning Map — Road to Qt6 & Dear ImGui
> **14 days · 2h/day · ~28h total** | Intermediate level · Project every day

---
[![Qodana](https://github.com/Unicorn7141/cpp-tutorial/actions/workflows/qodana_code_quality.yml/badge.svg?branch=master)](https://github.com/Unicorn7141/cpp-tutorial/actions/workflows/qodana_code_quality.yml)
---

## Overview

| | Detail |
|---|---|
| **Duration** | 2 Weeks |
| **Daily commitment** | Up to 2 hours |
| **Target** | Qt6 (Widgets + QML) + Dear ImGui |
| **C++ standard** | C++17 (C++20 concepts intro) |
| **Build system** | CMake 3.x + vcpkg |
| **Rule** | Every day ends with something you built and can run |

---

## WEEK 1 — Modern C++ Foundations

> **Milestone:** A working multi-threaded CLI sensor logger built entirely with modern C++17.

---

### Day 1 — Smart Pointers & Move Semantics

**Theory (45 min)**
- `unique_ptr`, `shared_ptr`, `weak_ptr` — when to use each
- Rvalue refs, `std::move`, `std::forward`, rule of 5
- `auto`, structured bindings, `std::optional`

**📦 Task: Memory-Safe Linked List**
Implement a singly linked list using only `unique_ptr<Node>` — no raw `new`/`delete` anywhere.
- `push_front()`, `pop_front()`, `print()`
- Add a move constructor to the list class
- Verify no memory leaks with valgrind or MSVC diagnostic

```cpp
struct Node {
    int value;
    std::unique_ptr<Node> next;
};
class LinkedList {
    std::unique_ptr<Node> head;
public:
    void push_front(int val);
    void pop_front();
    void print() const;
    LinkedList(LinkedList&&) noexcept; // you implement this
};
```

**Resources:**
- [cppreference C++17](https://en.cppreference.com/w/cpp/17)
- [LearnCpp — Smart Pointers](https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/)

---

### Day 2 — STL Containers & Algorithms

**Theory (45 min)**
- `vector`, `map`, `unordered_map`, `std::span`
- `std::sort`, `std::find_if`, `std::transform`, `std::ranges`
- Lambdas and captures

**📦 Task: Contact Book CLI**
Build a CLI contact manager stored in `std::unordered_map<std::string, Contact>`.
- Add / remove / search contacts
- Sort by name using `std::sort` on a copied `std::vector` of pairs
- Filter contacts by keyword using `std::find_if` + lambda
- Print a formatted table to stdout

```cpp
struct Contact { std::string name, phone, email; };
// Commands: add, remove, search <keyword>, list, quit
```

**Resources:**
- [cppreference Containers](https://en.cppreference.com/w/cpp/container)
- [cppreference Algorithms](https://en.cppreference.com/w/cpp/algorithm)

---

### Day 3 — OOP & Design Patterns

**Theory (45 min)**
- Virtual dispatch, pure virtual, CRTP
- Observer pattern (maps 1:1 to Qt signals/slots)
- Command pattern (GUI undo/redo systems)

**📦 Task: Event System with Observer Pattern**
Build a minimal pub/sub event system from scratch.
- `EventBus` class: stores listeners per event name
- `subscribe(eventName, callback)` and `emit(eventName, data)`
- At least 3 listener types: logger, counter, alert threshold
- Demonstrate unsubscribing a listener at runtime

```cpp
// Target usage
bus.subscribe("sensor_update", [](float val) { std::cout << "val: " << val; });
bus.emit("sensor_update", 42.5f);
```

**Resources:**
- [Refactoring.Guru — Observer](https://refactoring.guru/design-patterns/observer/cpp/example)
- [Refactoring.Guru — Command](https://refactoring.guru/design-patterns/command/cpp/example)

---

### Day 4 — Templates & Generics

**Theory (45 min)**
- Function/class templates, partial specialization
- Variadic templates, fold expressions
- C++20 `concept` and `requires` (brief intro)

**📦 Task: Type-Safe Ring Buffer**
Implement a generic `RingBuffer<T, N>` using templates.
- Fixed-size, no heap allocation
- `push()`, `pop()`, `peek()`, `isFull()`, `isEmpty()`
- Add a C++20 concept constraint: `T` must be trivially copyable
- Test with `float`, `int`, and a custom `SensorReading` struct

```cpp
template<typename T, std::size_t N>
requires std::is_trivially_copyable_v<T>
class RingBuffer {
    std::array<T, N> buf;
    std::size_t head = 0, tail = 0, count = 0;
public:
    bool push(const T& val);
    std::optional<T> pop();
};
```

**Resources:**
- [cppreference Templates](https://en.cppreference.com/w/cpp/language/templates)
- [cppreference Concepts](https://en.cppreference.com/w/cpp/language/constraints)

---

### Day 5 — CMake & vcpkg

**Theory (30 min)**
- CMake targets, `find_package`, `target_link_libraries`
- vcpkg manifest mode (`vcpkg.json`)
- `clang-format` and `clang-tidy` config files

**📦 Task: Proper CMake Project Setup**
Restructure your Day 4 ring buffer into a full CMake project.
- `CMakeLists.txt` with C++20 standard
- `vcpkg.json` manifest with `fmt` or `nlohmann-json` as a dependency
- `.clang-format` config — run it on all source files
- Separate `tests/` folder with a manual test runner or `Catch2` via vcpkg
- Working `cmake --install` target
