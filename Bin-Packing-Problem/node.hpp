/*
This is a node class template desgned to work with the max-heap.hpp template for a Max Heap,
the type P can be specified to set which parameter is the priority reference. Works for an y user-defined
types that can be compared with the > operator
*/

#ifndef NODE_HPP
#define NODE_HPP
template <typename P>
class PriorityNode {
    P priority;
    bool maxPriority;
    public:
    PriorityNode();
    PriorityNode(T priority);
    PriorityNode(const PriorityNode* rhs);
    void operator=(PriorityNode* rhs);
    void operator>(PriorityNode* rhs);
    void assignMaximumPriority();
    void setPriority(P priority);
    bool isMax() const;
};

#endif