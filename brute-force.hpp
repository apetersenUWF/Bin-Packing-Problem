#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP
#include <vector>
#include "bin.hpp"
class BP_BF{
  float* items;
  int numItems;
  public:
  BP_BF();
  BP_BF(float* items, int numItems);
  ~BP_BF();
  std::vector<Bin*> run();
};
#endif