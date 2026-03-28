#include "node.hpp"
#include "max-heap.hpp"
#include "bin.hpp"
#include "rand.hpp"
#include "brute-force.hpp"
#include "heuristic.hpp"
#include <iostream>

int main() {
    int numItems = 12;
    float items[numItems] = {0.41, 0.34, 0.245, 0.19, 0.59, 0.755, 0.33, 0.22, 0.51, 0.339, 0.81, 0.37};
    MaxHeap<PriorityNode<float>>* maxHeap = new MaxHeap<PriorityNode<float>>();
    BP_Heuristic* heuristic = new BP_Heuristic(items, numItems);
    BP_BF* solver = new BP_BF(items, numItems);
    std::vector<Bin> result = solver->run();
    std::cout << "Brute-Force Results: " << std::endl;
    for (int i = 0; i < result.size(); i++) {
        std::cout << "b" << i << ": ";
        result[i].print();
    }
    std::cout << "Online First Fit Results: " << std::endl;
    result = heuristic->runOnlineFF();
    for (int i = 0; i < result.size(); i++) {
        std::cout << "b" << i << ": ";
        result[i].print();
    }
    std::cout << "Online Best Fit Results: " << std::endl;
    result = heuristic->runOnlineBF();
    for (int i = 0; i < result.size(); i++) {
        std::cout << "b" << i << ": ";
        result[i].print();
    }
    std::cout << "Online Next Fit Results: " << std::endl;
    result = heuristic->runOnlineNF();
    for (int i = 0; i < result.size(); i++) {
        std::cout << "b" << i << ": ";
        result[i].print();
    }
    delete solver;
    return 0;
}
