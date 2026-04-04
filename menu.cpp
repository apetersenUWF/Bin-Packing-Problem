/***************************************************************
 Ayden Petersen
menu.cpp
Project 4

This file contains the Menu class function definitions
necessary to load the items for the bin packing problem, perform
the brute-force and heuristic algorithms, and report the results to
the terminal.

The bruteForceApplicable variable designates whether the problem is of
a size that can be solved in a reasonable amount of time with the permutation
algorithm. If the number of items is over 12 this will be changed to false
and only the heuristics will be performed
***************************************************************/
#include "menu.hpp"
#include "heuristic.hpp"
#include "brute-force.hpp"
#include "rand.hpp"
#include <fstream>
#include <iostream>
    Menu::Menu(): items(nullptr), numItems(0), mathematicalMinimumBins(0), bruteForceApplicable(false) {}
    Menu::~Menu() {delete [] items;}

    bool Menu::loadItems(std::string filename) {
        std::ifstream inFS;
        inFS.open(filename);
        if (!inFS.is_open()) return false;
        std::vector<float> validItems;
        std::string line;
        getline(inFS, line);
        numItems = stoi(line);//first line is the number of items
        for (int i = 0; i < numItems; i++) {
            (getline(inFS, line));
            float item = stof(line);
            if (item > 0 && item <= 1) validItems.push_back(item);
            else std::cout << "Invalid Item detected and discarded -> " << item << std::endl;
        }
        inFS.close();
        numItems = validItems.size();
        items = new float[numItems];
        float total = 0.0;
        for (int i = 0; i < numItems; i++) {
            items[i] = validItems[i];
            total += items[i];
        }
        mathematicalMinimumBins = static_cast<int>(total+0.99999);
        if (numItems > 0 && numItems < 13) bruteForceApplicable = true;
        return true;
    }

    bool Menu::loadRandomItemFile(int numItems) {
        std::ofstream oFS("randomitems.txt");
        if (!oFS.is_open()) return false;
        oFS << numItems << std::endl;
        for (int i = 0; i < numItems; i++) oFS << getRandomFloat(0,1) << std::endl;
        oFS.close();
        return true;
    }

    void Menu::printResult(std::vector<Bin> result) {
        for (long unsigned int i = 0; i < result.size(); i++) {
            std::cout << "b" << i << ": ";
            result[i].print();
        }
    }

    void Menu::run() {
        std::vector<Bin> optimal, onlineFF, onlineBF, onlineNF, offlineFF, offlineBF;
        BP_Heuristic* heuristic = new BP_Heuristic(items, numItems);
        if (bruteForceApplicable) {
        BP_BF* solver = new BP_BF(items, numItems);
        optimal = solver->run();
        delete solver;
        }
        onlineFF = heuristic->runOnlineFF();
        onlineBF = heuristic->runOnlineBF();
        onlineNF = heuristic->runOnlineNF();
        offlineFF = heuristic->runOfflineFF();
        offlineBF = heuristic->runOfflineBF();
        delete heuristic;
        std::cout << "Policy" << std::endl;
        std::cout << std::endl;
        std::cout << "Total Bins Used" << std::endl;
        std::cout << "Mathematic Optimal" << std::endl;
        std::cout << mathematicalMinimumBins << std::endl;
        if (bruteForceApplicable) {
        std::cout << "Optimal Solution" << std::endl;
        std::cout << optimal.size() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Online Algorithm" << std::endl;
        std:: cout << "First Fit (" <<	onlineFF.size() << ")" << std::endl;
        std:: cout << "Next Fit (" <<	onlineNF.size() << ")" << std::endl;
        std:: cout << "Best Fit (" <<	onlineBF.size() << ")" << std::endl;
        std::cout << "Offline Algorithm" << std::endl;
        std:: cout << "First Fit (" <<	offlineFF.size() << ")" << std::endl;
        std:: cout << "Best Fit (" <<	offlineBF.size() << ")" << std::endl;
        std::cout << std::endl;
        if (bruteForceApplicable) {
        std::cout << "Brute-Force Results: " << std::endl;
        printResult(optimal);
        std::cout << std::endl;
        }
        std::cout << "Online First Fit Results: " << std::endl;
        printResult(onlineFF);
        std::cout << std::endl;
        std::cout << "Online Best Fit Results: " << std::endl;
        printResult(onlineBF);
        std::cout << std::endl;
        std::cout << "Online Next Fit Results: " << std::endl;
        printResult(onlineNF);
        std::cout << std::endl;
        std::cout << "Offline First Fit Results: " << std::endl;
        printResult(offlineFF);
        std::cout << std::endl;
        std::cout << "Offline Best Fit Results: " << std::endl;
        printResult(offlineBF);
    }