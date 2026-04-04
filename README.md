# Bin-Packing-Problem-Project

This program contains solutions to the canonical version of the bin packing problem. Each bin has a 
maximum capacity of 1.0 and every item will be of size (0 < item <= 1.0). This program considers
a brute-force permutation algorithm to check every arrangement of the items in factorial time, as 
well as 5 heuristic algorithms to find a close but not strictly optimal solution in polynomial time.
The goal of each algorithm is to pack the items in the smallest number of bins possible.

The purpose of the program is to provide the user with the results of each of these algorithms to see the
different results obtained by the polynomial versus non-polynomial algorithms. Another use is to use the
heuristic algorithms to solve the problem for number of items far exceeding the number you could solve with
the brute force algorithm. The heurisitcs finish quickly for n up to roughly 100,000 while the brute force
stops being usable around n = 13.

The algorithms considered are:

- ***Brute-Force Strictly Optimal***
- ***Online First Fit Heuristic***
- ***Online Best Fit Heuristic***
- ***Online Next Fit Heuristic***
- ***Offline First Fit Heuristic***
- ***Offline Best Fit Heuristic***

Online algorithms can only see one item at a time in the order they are sent.
Offline algorithms can see all the items beforehand and sort/arrange them any way before processing.

The number of bins used by each algorithm will be displayed upon running as well as the mathematically
optimal solution.

# How to Use

This program comes with a Makefile, to use it run the command "make" in the command line interface.
This will generate an executable called "run".
Verify that the data file "items.txt" is in the same directory as the executable.
Verify that the "items.txt" file contains the number of items on the first lime, and a float representing an 
item on each line following that.

Issue the command "./run" in the command line to run the executable.
No user interaction will be required beyond this point, the program will run the correct algorithms and
display the results automatically. If the file used has a number of items < 13, the brute force will execute,
otherwise only the heurisitcs will execute. In the terminal the program will display a table summarizing the results
that will look similar to this:

Policy

Total Bins Used
Mathematic Optimal
x
Optimal Solution
x

Online Algorithm
First Fit (x)
Next Fit (x)
Best Fit (x)
Offline Algorithm
First Fit (x)
Best Fit (x)

The mathematic optimal is calculated as the sum of the total item weights, rounded up to the nearest integer.
The optimal solution is the result found by the brute force, this will not be displayed for n larger than 12.

After this the program will display all of the bins and how they were packed for each solution.

Lastly, to run the program without the items.txt file for any n, use the menu->loadRandomItems(n) function to generate
a .txt file containing n random items. This file can then be loaded with the ->loadItems(RANDOM_ITEM_FILE) function and 
run with the ->run() function.
