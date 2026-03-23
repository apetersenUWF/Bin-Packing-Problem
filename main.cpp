#include "node.hpp"
#include "max-heap.hpp"
#include "bin.hpp"
#include "rand.hpp"
#include "brute-force.hpp"
#include <iostream>

int main() {
    int numItems = 12;
    float items[numItems] = {0.41, 0.34, 0.245, 0.19, 0.59, 0.755, 0.33, 0.22, 0.51, 0.339, 0.81, 0.37};
    MaxHeap<PriorityNode<float>>* maxHeap = new MaxHeap<PriorityNode<float>>();
    BP_BF* solver = new BP_BF(items, numItems);
    std::vector<Bin> result = solver->run();
    for (int i = 0; i < result.size(); i++) {
        std::cout << "b" << i << ": ";
        result[i].print();
    }
    delete solver;
    return 0;
}
