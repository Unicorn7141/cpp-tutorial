#include <iostream>
#include "RingBuffer.h"

int main() {
    const int N = 10;
    RingBuffer<int, N> ring;

    for (int i = 1; i <= N; ++i) {
        ring.push(i*(i << 2));
    }

    ring.print();

    return 0;
}