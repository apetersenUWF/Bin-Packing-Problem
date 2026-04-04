CXX = g++

CXXFLAGS = -std=c++11 -Wall

OBJS = bin.o main.o rand.o brute-force.o heuristic.o menu.o

EXEC = run

TEXT_FILES = randomitems.txt

run: $(OBJS)
				$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

bin.o : bin.hpp
rand.o : rand.hpp
brute-force.o : brute-force.hpp rand.hpp
heuristic.o : heuristic.hpp max-heap.hpp node.hpp
menu.o : menu.hpp heuristic.hpp brute-force.hpp
main.o : node.hpp brute-force.hpp bin.hpp heuristic.hpp max-heap.hpp

clean :
				rm -f $(EXEC) $(TEXT_FILES) $(OBJS)