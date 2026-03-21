/***************************************************************
  Ayden Petersen
  brute-force.cpp
  Project 4

  This file contains the necessary logic to solve for the optimal solution
  in the bin packing problem using a permutation checker.
***************************************************************/
#include "brute-force.hpp"
#include "rand.hpp"
#include <climits>
  BP_BF::BP_BF() {
    items = nullptr;
    numItems = 0;
  }
  BP_BF::BP_BF(float* items, int numItems) {
    items = new float[numItems];
    this->numItems = numItems;
    for (int i = 0; i < numItems; i++) {
      this->items[i] = items[i];
    }
  }
  BP_BF::~BP_BF() {
    delete [] items;
  }
  std::vector<Bin*> BP_BF::run() {
    int optimal = INT_MAX;
    std::vector<Bin*> bins, optimalBins;
    Bin* curr = new Bin();
    do {
      for (int i = 0; i < numItems; i++) {
        if (!curr->insert(items[i])) {//if item doesnt fit in the current bin
          bins.push_back(curr);//save the bin
          curr = new Bin(items[i]);//make a new bin with the item
        }
      }
      bins.push_back(curr);//add the last bin
      if (bins.size() < optimal) {//if this was the lowest number of bins found
        optimal = bins.size();
        optimalBins = bins;
      }
    } while (perm1(items));
    return optimalBins;
  }