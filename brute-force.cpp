/***************************************************************
  Ayden Petersen
  brute-force.cpp
  Project 4

  This file contains the necessary logic to solve for the optimal solution
  in the bin packing problem using a permutation checker.
***************************************************************/
#include "brute-force.hpp"
#include "rand.hpp"
  BP_BF::BP_BF() {
    items = nullptr;
    s = nullptr;
    numItems = 0;
  }
  BP_BF::BP_BF(float* items, int numItems) {
    this->items = new float[numItems];
    s = new int[numItems];
    this->numItems = numItems;
    for (int i = 0; i < numItems; i++) {
      this->items[i] = items[i];
      s[i] = i;
    }
  }
  BP_BF::~BP_BF() {
    delete [] items;
    delete [] s;
  }
  std::vector<Bin> BP_BF::run() {
    float binMax = 1.0;
    int optimalBins = numItems;
    int bestOrder[numItems];
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {total += items[i];}//calculate total item weight to determine mathematical lower bound
    do {
      float x = 0.0;
      int bins = 1;//start at 1 bin
      for (int i = 0; i < numItems; i++) {
        float item = items[s[i]];
        if ((x + item) <= binMax) {x += item;}//if item fits dont go to a new bin
        else {//item doesnt fit, count another bin
          bins++;
          x = item;
        }
      }
      if (bins < optimalBins) {//copy the best configuration
        for (int i = 0; i < numItems; i++) {bestOrder[i] = s[i];}
        optimalBins = bins;
        if (optimalBins == (static_cast<int>(total+0.999999))) break;//mathematically optimal soln found
      }
    } while (perm1(s, numItems));
    //best order is found, now pack into bin bjects for return
    std::vector<Bin> optimal;
    Bin curr = Bin();
    for (int i = 0; i < numItems; i++) {
      float item = items[bestOrder[i]];
      if (!curr.insert(item)) {
        optimal.push_back(curr);
        curr = Bin(item);
      }
    }
    optimal.push_back(curr);
    return optimal;
  }