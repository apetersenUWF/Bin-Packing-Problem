#include "node.hpp"
#include "max-heap.hpp"
#include "bin.hpp"
#include "rand.hpp"
#include "brute-force.hpp"
#include <iostream>

int main() {
    int numItems = 8;
    float items[8] = {0.1, 0.33, 0.11, 0.25, 0.8, 0.59, 0.74, 0.25};
    MaxHeap<PriorityNode<float>>* maxHeap = new MaxHeap<PriorityNode<float>>();
    BP_BF* solver = new BP_BF(items, numItems);
    solver->run();
    delete solver;
    return 0;
}
