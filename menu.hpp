#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "bin.hpp"
const std::string RANDOM_ITEM_FILE = "randomitems.txt";
class Menu{
    float* items;
    int numItems;
    int mathematicalMinimumBins;//the mathematic minimum number of possible bins = ROUNDUP(total item weight)
    bool bruteForceApplicable;
    void printResult(std::vector<Bin> result);
    public:
    Menu();
    ~Menu();
    bool loadItems(std::string filename);
    bool loadRandomItemFile(int numItems);
    void run();
};
#endif