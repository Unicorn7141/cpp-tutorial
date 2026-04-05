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
