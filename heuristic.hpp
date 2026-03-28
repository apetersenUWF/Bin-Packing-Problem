#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP
#include "bin.hpp"
#include <vector>
class BP_Heuristic{
    float* items;
    int numItems;
    public:
    BP_Heuristic();
    BP_Heuristic(float* items, int numItems);
    ~BP_Heuristic();
    std::vector<Bin> runOnlineFF();
    std::vector<Bin> runOnlineNF();
    std::vector<Bin> runOnlineBF();

    std::vector<Bin> runOfflineFF();
    std::vector<Bin> runOfflineBF();
};
#endif