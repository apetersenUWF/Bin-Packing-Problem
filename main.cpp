#include "node.hpp"
#include "max-heap.hpp"
#include "bin.hpp"
#include "rand.hpp"
#include <iostream>

int main() {
    MaxHeap<PriorityNode<float>>* maxHeap = new MaxHeap<PriorityNode<float>>();
    Bin* b1 = new Bin();
    for (int i = 0; i < 20; i++) {
        PriorityNode<float>* curr = new PriorityNode<float>(getRandomFloat(0, 1));
        maxHeap->insert(curr);
    }
    while (!maxHeap->isEmpty()) {
        std::cout << maxHeap->serve()->getPriority() << std::endl;
    }
    return 0;
}
