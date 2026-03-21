CXX = g++

CXXFLAGS = -std=c++11 -Wall

OBJS = bin.o main.o rand.o

EXEC = run

TEXT_FILES =

run: $(OBJS)
				$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

bin.o : bin.hpp
main.o : node.hpp brute-force.hpp bin.hpp
rand.o : rand.hpp

clean :
				rm -f $(EXEC) $(TEXT_FILES) $(OBJS)