#include <iostream>

#include "EventBus.h"

int main() {
    EventBus bus;
    int counter = 0;

    bus.subscribe<float>("sensor_data", [](const float val) { std::cout << "[LOG] New value registered: " << val << "\n"; });
    bus.subscribe<float>("sensor_data", [&counter](const float val) { counter++; });
    bus.subscribe<float>("sensor_data", [](const float val) { if (val > 100.0f) std::cout << "[ALERT] Sensor reading exceeded the threshold\n"; });

    bus.emit("sensor_data", 90.0f);
    bus.emit("sensor_data", 109.8f);
    bus.unsubscribe("sensor_data");

    return 0;
}