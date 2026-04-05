#include <iostream>
#include "EventBus.h"

using ListenerID = std::size_t;

int main() {
    EventBus bus;
    int cnt = 0;

    auto logger = [](const float val) { std::cout << "[LOG] New value registered: " << val << "\n"; };
    auto counter = [&cnt](float) { cnt++; };;
    auto alert = [](const float val) {
        if (val > 100.0f) std::cout << "[ALERT] Value exceeds the threshold!\n";
    };

    const auto id1 = bus.subscribe<float>("sensor_data", logger);
    const auto id2 = bus.subscribe<float>("sensor_data", counter);
    const auto id3 = bus.subscribe<float>("sensor_data", alert);

    bus.emit("sensor_data", 90.0f);
    bus.emit("sensor_data", 109.8f);
    bus.unsubscribe("sensor_data", id3);
    cnt--;
    bus.emit("sensor_data", 112.3f);
    std::cout << "Listeners: " << cnt << std::endl;


    return 0;
}