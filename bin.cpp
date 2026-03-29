/***************************************************************
  Ayden Petersen
  bin.cpp
  Project 4

  This file contains implementations of the Bin class used in algorithms
  for the canonical version of the bin-packing problem.

  The bin size is by default 1.0 and the items will be of size <= 1.0
  The bin has no limit on the number of items it can hold
***************************************************************/
#include "bin.hpp"
#include <iostream>
/*CONSTRUCTORS******************************************************************************/
    Bin::Bin(): capacity(1.0), size(0.0) {}//creates an empty bin

    Bin::Bin(float item) {//create a bin with 1 item
        capacity = 1.0;
        size = item;
        items.push_back(item);
    }
/*LOGIC******************************************************************************/
    float Bin::fit(float item) const {return (capacity - (size + item));}//returns the amount of room left in the box if you inserted item

    bool Bin::insert(float item) {//inserts item if it fits, else returns false
        if (fit(item) < 0) return false;//item will not fit
        else {
            size += item;
            items.push_back(item);
            return true;
        }
    }
/*GETTERS******************************************************************************/
    float Bin::getSize() const {return size;}

    void Bin::print() {
        for (long unsigned int i = 0; i < items.size(); i++) {
            if (i == items.size() - 1) {//if last item, dont add comma, end the line
                std::cout << items[i] << std::endl;
            }
            else {std::cout << items[i] << ", ";}
        }
    }