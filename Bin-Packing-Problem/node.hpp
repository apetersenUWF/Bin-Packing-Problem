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
    bool isMax() const;
    public:
    PriorityNode();
    PriorityNode(P priority);
    PriorityNode(const PriorityNode* rhs);
    void operator=(PriorityNode* rhs);
    bool operator>(PriorityNode* rhs);
    void assignMaximumPriority();
    void setPriority(P priority);
    P getPriority() const;
};
    template <typename P>
    PriorityNode<P>::PriorityNode() {maxPriority = false;}
    template <typename P>
    PriorityNode<P>::PriorityNode(P priority) {
        this->priority = priority;
        maxPriority = false;
    }
    template <typename P>
    PriorityNode<P>::PriorityNode(const PriorityNode* rhs) {}
    template <typename P>
    void PriorityNode<P>::operator=(PriorityNode* rhs) {}
    template <typename P>
    bool PriorityNode<P>::operator>(PriorityNode* rhs) {
        if (rhs->isMax()) return false;
        if (maxPriority) return true;
        return (priority > rhs-getPriority());
    }
    template <typename P>
    void PriorityNode<P>::assignMaximumPriority() {maxPriority = true;}
    template <typename P>
    void PriorityNode<P>::setPriority(P priority) {this->priority = priority;}
    template <typename P>
    P PriorityNode<P>::getPriority() const {return priority;}
    template <typename P>
    bool PriorityNode<P>::isMax() const {return maxPriority;}
#endif