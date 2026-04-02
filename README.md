# C++ Learning Map — Road to Qt6 & Dear ImGui
> **14 days · 2h/day · ~28h total** | Tailored for embedded engineers

---

## 📋 Overview

| | Detail |
|---|---|
| **Duration** | 2 Weeks |
| **Daily commitment** | Up to 2 hours |
| **Target** | Qt6 (Widgets + QML) + Dear ImGui |
| **C++ standard** | C++17 (C++20 concepts intro) |
| **Build system** | CMake 3.x + vcpkg |

---

## WEEK 1 — Modern C++ Foundations

> **Milestone:** After this week you'll write confident C++17 code with clean memory management.

---

### Day 1 — C++17 Essentials Review
**Tags:** 📚 Theory · ⚙️ Practice  
**Time:** 1h theory · 1h mini exercises

**What to cover:**
- Smart pointers: `unique_ptr`, `shared_ptr`, `weak_ptr`
- Move semantics: rvalue refs, `std::move`, `std::forward`
- `auto`, structured bindings, `if constexpr`
- Range-based for, `[[nodiscard]]`, `std::optional`

**Resources:**
- [cppreference C++17](https://en.cppreference.com/w/cpp/17)
- [LearnCpp — Smart Pointers & Move Semantics](https://www.learncpp.com/cpp-tutorial/introduction-to-smart-pointers-move-semantics/)

---

### Day 2 — STL Containers & Algorithms
**Tags:** 📚 Theory · ⚙️ Practice  
**Time:** 1h theory · 1h coding

**What to cover:**
- `vector`, `map`, `unordered_map`, `set`, `std::span`
- `std::algorithm` pipeline: `sort`, `find_if`, `transform`, `ranges`
- Lambdas, closures, capturing strategies
- Iterator invalidation rules

**Resources:**
- [cppreference STL Containers](https://en.cppreference.com/w/cpp/container)
- [cppreference Algorithms](https://en.cppreference.com/w/cpp/algorithm)

---

### Day 3 — OOP & Design Patterns
**Tags:** 📚 Theory · ⚙️ Practice  
**Time:** 45min theory · 75min project

**What to cover:**
- Inheritance, virtual dispatch, pure virtual
- Rule of 5: destructor, copy ctor, copy assign, move ctor, move assign
- CRTP (Curiously Recurring Template Pattern)
- **Observer pattern** — maps directly to Qt signals/slots
- **Command pattern** — GUI action/undo systems

**Resources:**
- [Refactoring.Guru — C++ Patterns](https://refactoring.guru/design-patterns/cpp)
- [LearnCpp OOP](https://www.learncpp.com/cpp-tutorial/welcome-to-object-oriented-programming/)

---

### Day 4 — Templates & Generics
**Tags:** 📚 Theory · ⚙️ Practice  
**Time:** 1h theory · 1h exercises

**What to cover:**
- Function templates, class templates
- Template specialization and partial specialization
- Variadic templates
- C++20 Concepts — `requires`, `concept` (preview, used in Qt6)
- Why this matters: ImGui internals are heavily templated

**Resources:**
- [cppreference Templates](https://en.cppreference.com/w/cpp/language/templates)
- [cppreference Constraints & Concepts](https://en.cppreference.com/w/cpp/language/constraints)

---

### Day 5 — Build Systems & Tooling
**Tags:** 🛠 Tools · ⚙️ Practice  
**Time:** 1.5h hands-on · 30min reading

**What to cover:**
- CMake 3.x: `CMakeLists.txt`, targets, linking, `find_package`
- vcpkg: install Qt6, Dear ImGui, SDL2 via manifest mode
- `clang-format` + `clang-tidy` integration
- GDB / MSVC debugger basics
- **Critical:** Qt6 CMake integration (`qt_add_executable`, `qt_add_qml_module`)

**Resources:**
- [CMake Official Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
- [vcpkg Documentation](https://learn.microsoft.com/en-us/vcpkg/)

---

### Day 6 — Concurrency Basics
**Tags:** 📚 Theory · ⚙️ Practice  
**Time:** 1h theory · 1h examples

**What to cover:**
- `std::thread`, `std::jthread` (C++20)
- `std::mutex`, `std::lock_guard`, `std::unique_lock`
- `std::condition_variable`
- `std::async`, `std::future`, `std::promise`
- Why this matters: GUI main thread must never block

**Resources:**
- [cppreference Thread Support](https://en.cppreference.com/w/cpp/thread)

---

### Day 7 — Week 1 Project: CLI Tool *(2h full project)*
**Tags:** 🔨 Project · 🔄 Review  
**Time:** 2h full build

**Project:** Multi-threaded sensor data logger CLI
- Simulates sensor readings on a worker thread
- Main thread processes and logs data with timestamp
- Uses `vector`, lambdas, `mutex`, `unique_ptr`
- CMake project with vcpkg dependency

**Resources:**
- [Modern C++ Features Reference](https://github.com/AnthonyCalandra/modern-cpp-features)

---

## WEEK 2 — Qt6 & Dear ImGui

> **Milestone:** By Day 14 you'll have working Qt6 and Dear ImGui apps you built yourself.

---

### Day 8 — Qt6 Setup & Architecture
**Tags:** 🛠 Tools · 📚 Theory  
**Time:** 1h setup · 1h architecture

**What to cover:**
- Install Qt6 via vcpkg or Qt Online Installer
- CMake integration: `find_package(Qt6)`, `qt_add_executable`
- QObject model, `Q_OBJECT` macro, MOC (Meta-Object Compiler)
- Signals & Slots architecture overview
- Qt's memory ownership model (parent-child tree)

**Resources:**
- [Qt6 Getting Started](https://doc.qt.io/qt-6/gettingstarted.html)
- [Qt CMake Guide](https://doc.qt.io/qt-6/cmake-get-started.html)

---

### Day 9 — Qt Widgets Essentials
**Tags:** 🖥 GUI · ⚙️ Practice  
**Time:** 30min reading · 90min coding

**What to cover:**
- `QMainWindow`, `QWidget`, `QDialog`
- Layouts: `QVBoxLayout`, `QHBoxLayout`, `QGridLayout`
- Common widgets: `QLabel`, `QLineEdit`, `QPushButton`, `QComboBox`, `QSlider`
- Menu bar, toolbar, status bar
- **Build:** Your first real desktop window

**Resources:**
- [Qt Widgets Docs](https://doc.qt.io/qt-6/qtwidgets-index.html)
- [Qt Widgets Examples](https://doc.qt.io/qt-6/qtwidgets-examples.html)

---

### Day 10 — Signals, Slots & MVC
**Tags:** 🖥 GUI · ⚙️ Practice  
**Time:** 1h theory · 1h project

**What to cover:**
- Custom signals/slots with `emit`
- `connect()` syntax (new pointer-to-member style)
- `QAbstractItemModel`, `QTableView`, `QListView`
- **Build:** Live data table (sensor dashboard mockup)
- Thread-safe GUI updates with `QMetaObject::invokeMethod`

**Resources:**
- [Signals & Slots Docs](https://doc.qt.io/qt-6/signalsandslots.html)
- [Model/View Programming](https://doc.qt.io/qt-6/model-view-programming.html)

---

### Day 11 — Qt Quick / QML Intro
**Tags:** 🖥 GUI · 📚 Theory  
**Time:** 1h tutorial · 1h build

**What to cover:**
- QML syntax: elements, properties, property bindings
- Qt Quick Controls 2 components
- Animations and state machines in QML
- Exposing C++ classes to QML with `Q_PROPERTY`, `Q_INVOKABLE`
- When to use Widgets vs QML

**Resources:**
- [QML Tutorial](https://doc.qt.io/qt-6/qml-tutorial.html)
- [Integrating C++ and QML](https://doc.qt.io/qt-6/qtqml-cppintegration-overview.html)

---

### Day 12 — Dear ImGui Setup & Core
**Tags:** 🖥 GUI · 🛠 Tools  
**Time:** 1h setup · 1h coding

**What to cover:**
- Clone ImGui + integrate via vcpkg
- Backend: **GLFW + OpenGL3** (recommended for your RX 9070 XT)
- Immediate mode vs retained mode paradigm
- Core loop: `NewFrame()` → widgets → `Render()`
- `ImGui::Begin/End`, `Text`, `Button`, `InputFloat`, `SliderInt`
- Explore `imgui_demo.cpp` — the best reference

**Resources:**
- [Dear ImGui GitHub](https://github.com/ocornut/imgui)
- [ImGui Demo Source](https://github.com/ocornut/imgui/blob/master/imgui_demo.cpp)

---

### Day 13 — ImGui Widgets & Custom UI
**Tags:** 🖥 GUI · ⚙️ Practice  
**Time:** 30min reading · 90min project

**What to cover:**
- `ImGui::Table` API (multi-column data)
- **ImPlot** library for real-time charts/plots
- Docking API (`ImGuiConfigFlags_DockingEnable`)
- Multi-viewport support
- Custom draw calls with `ImDrawList`
- **Build:** Debug overlay panel with live charts

**Resources:**
- [ImPlot Library](https://github.com/epezent/implot)
- [Awesome ImGui Extensions](https://github.com/HankiDesign/awesome-imgui)

---

### Day 14 — Capstone Project *(2h full build)*
**Tags:** 🔨 Project · 🔄 Review  
**Time:** 2h capstone

**Project:** Sensor Dashboard — Qt6 + ImGui
- **Qt6 main window:** menu, toolbar, live `QTableView` with sensor data
- **Embedded ImGui overlay:** debug panel, real-time ImPlot chart
- **Worker thread:** generates sensor data, Qt signals update the table
- **CMake:** single project linking Qt6 + ImGui + ImPlot
- Bonus: add `QSettings` to save window state

**Resources:**
- [Qt + ImGui Integration Example](https://github.com/huxingyi/qt-imgui)
- [Awesome ImGui](https://github.com/HankiDesign/awesome-imgui)

---

## 📊 Daily Schedule Suggestion
