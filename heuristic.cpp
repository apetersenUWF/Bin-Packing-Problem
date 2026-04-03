/***************************************************************
  Ayden Petersen
  heuristic.cpp
  Project 4

  This file contains the necessary logic to perform the various heuristic
  algorithms for the Bin-Packing-Problem.
  
  Algorithms include:
  Online First Fit
  Online Next Fit
  Online Best Fit

  Offline First Fit
  Offline Best Fit

***************************************************************/
#include "heuristic.hpp"
#include "max-heap.hpp"
#include "node.hpp"

/*CONSTRUCTORS/DESTRUCTOR******************************************************************************/
    BP_Heuristic::BP_Heuristic(): items(nullptr), numItems(0) {}

    BP_Heuristic::BP_Heuristic(float* items, int numItems) {
        this->numItems = numItems;
        this->items = new float[numItems];
        for (int i = 0; i < numItems; i++) {this->items[i] = items[i];}
    }

    BP_Heuristic::~BP_Heuristic() {delete [] items;}

/*ONLINE-ALGORITHMS******************************************************************************/
    std::vector<Bin> BP_Heuristic::runOnlineFF() {//Online First Fit
        //For each item, the list of bins is scanned through until
        //A bin is found where the item can fit. Then the item is placed there
        //If no place is found, a new bin is created with the item
        std::vector<Bin> bins;
        Bin curr;
        bins.push_back(curr);
        for (int i = 0; i < numItems; i++) {//for each item in the list
            for (long unsigned int j = 0; j < bins.size(); j++) {//scan through all the available bins for one that fits
                if (bins[j].fit(items[i]) >= 0) {//if a bin that fits the item is located
                    bins[j].insert(items[i]);//insert there
                    break;
                }
                if (j == bins.size() - 1) {//if it didnt fit in any bins
                    curr = Bin(items[i]);//make a new bin with the item
                    bins.push_back(curr);//and add it to bins
                    break;
                }
            }
        }
        return bins;
    }

    std::vector<Bin> BP_Heuristic::runOnlineNF() {//Online Next Fit
        //For each item, the algorithm checks if the item will fit in the same bin as the last tiem
        //The current bin (curr). If the item fits, place it there, otherwise make a new bin
        //With the item.
        std::vector<Bin> bins;
        Bin curr;
        for (int i = 0; i < numItems; i++) {
            if (!curr.insert(items[i])) {
                bins.push_back(curr);
                curr = Bin(items[i]);
            }
        }
        bins.push_back(curr);//add the last bin
        return bins;
    }
    std::vector<Bin> BP_Heuristic::runOnlineBF() {//Online Best Fit
        //For each item, the list of bins is scanned through and the algorithm calculates
        //How full each bin would be with the item. The item will be inserted in the bin
        //Which would become the fullest without overflowing after recieving the item.
        //If no place is found, a new bin is created with the item
        std::vector<Bin> bins;
        Bin curr;
        bins.push_back(curr);
        for (int i = 0; i < numItems; i++) {//for each item in the list
            int bestFitIndex = -1;
            float bestFit = 1;
            for (long unsigned int j = 0; j < bins.size(); j++) {//scan through all the available bins for the on that fits best
                float fit = bins[j].fit(items[i]);//remaining room after fitting the item
                if ((fit < bestFit) && fit >= 0) {//if a bin that fits the item is lower than all other bins so far
                    bestFitIndex = j;//save that index and value
                    bestFit = fit;
                }
            }
            if (bestFitIndex == -1) {//item didnt fit in any available bins
                curr = Bin(items[i]);//make new bin with the item
                bins.push_back(curr);//add it to available bins
            }
            else {//an ideal bin was found
                bins[bestFitIndex].insert(items[i]);//insert the item in the bin which becomes the most full
            }
        }
        return bins;
    }

/*OFFLINE-ALGORITHMS******************************************************************************/
    std::vector<Bin> BP_Heuristic::runOfflineFF() {//Offline First Fit
        //For each item, with items checked in descending order, the list of bins is scanned 
        //through until a bin is found where the item can fit. Then the item is placed there
        //If no place is found, a new bin is created with the item
        std::vector<PriorityNode<float>> list;//vector of nodes to create the max heap
        for (int i = 0; i < numItems; i++) {//create a node for each item
            PriorityNode<float> curr = PriorityNode<float>(items[i]);
            list.push_back(curr);
        }
        MaxHeap<PriorityNode<float>> maxHeap(list, numItems);//create a max heap to easily find the biggest item
        std::vector<Bin> bins;
        Bin curr = Bin();
        bins.push_back(curr);
        for (int i = 0; i < numItems; i++) {
            float item = (maxHeap.serve()).getPriority();
            for (long unsigned int j = 0; j < bins.size(); j++) {
                if (bins[j].fit(item) >= 0) {
                    bins[j].insert(item);
                    break;
                }
                if (j == bins.size() - 1) {//if it didnt fit in any bins
                    curr = Bin(item);//make a new bin with the item
                    bins.push_back(curr);//and add it to bins
                    break;
                }
            }
        }
        return bins;
    }
    std::vector<Bin> BP_Heuristic::runOfflineBF() {//Offline Best Fit
        //For each item, with items checked in descending order, the list of bins is scanned
        //through and the algorithm calculates How full each bin would be with the item.
        //The item will be inserted in the bin Which would become the fullest without overflowing 
        //after recieving the item.
        //If no place is found, a new bin is created with the item
        std::vector<PriorityNode<float>> list;//vector of nodes to create the max heap
        for (int i = 0; i < numItems; i++) {//create a node for each item
            PriorityNode<float> curr = PriorityNode<float>(items[i]);
            list.push_back(curr);
        }
        MaxHeap<PriorityNode<float>> maxHeap(list, numItems);//create a max heap to easily find the biggest item
        std::vector<Bin> bins;
        Bin curr = Bin();
        for (int i = 0; i < numItems; i++) {//for each item in the list
            float item = maxHeap.serve().getPriority();
            int bestFitIndex = -1;
            float bestFit = 1;
            for (long unsigned int j = 0; j < bins.size(); j++) {//scan through all the available bins for the on that fits best
                float fit = bins[j].fit(item);//remaining room after fitting the item
                if ((fit < bestFit) && fit >= 0) {//if a bin that fits the item is lower than all other bins so far
                    bestFitIndex = j;//save that index and value
                    bestFit = fit;
                }
            }
            if (bestFitIndex == -1) {//item didnt fit in any available bins
                curr = Bin(item);//make new bin with the item
                bins.push_back(curr);//add it to available bins
            }
            else {//an ideal bin was found
                bins[bestFitIndex].insert(item);//insert the item in the bin which becomes the most full
            }
        }
        return bins;
    }