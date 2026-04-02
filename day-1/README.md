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
