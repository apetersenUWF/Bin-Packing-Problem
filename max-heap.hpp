/***************************************************************
Ayden Petersen
max-heap.hpp
Project 4

This is a max heap class template designed to work for any node class
with operator overloading and maxPriority member for the sentinel node.

The purpose of this class is to efficiently find the max size items
in the offline solutions to the bin packing problem
***************************************************************/

#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP
#include <vector>
//#include <iostream> //for testing
#include "node.hpp"
const int DEFAULT_MAXHEAP_CAPACITY = 200;//defines the default size for the max heap
template <typename T>
class MaxHeap{
  int size;//holds the effective size
  int capacity;//holds the maximum capacity
  std::vector<T> priorityQueue;////holds all the items in a maxHeap structure
  void percolateUp(int index);//used internally to maintain structure
  void percolateDown(int index);//used internally to maintain structure
  int parent(int index) const;//returns parent given an index
  int LChild(int index) const;//returns lchild given an index
  int RChild(int index) const;//returns rchild given an index
  void swap(int indexA, int indexB);//swaps two items positions, used for maintaining structure
  public:
  MaxHeap();
  MaxHeap(int capacity);
  MaxHeap(std::vector<T> items, int n);
  bool insert(T item);//inserts an item into the maxHeap
  T serve();//pops the top item and returns it
  bool isEmpty() const;//checks if the heap is empty
  int getSize() const;//returns effective size of the heap
  T retrieve() const;//returns the highest priority item
  //void print() const; //for testing
};
/*CONSTRUCTORS/DESTRUCTOR******************************************************************************/
  template <typename T>
  MaxHeap<T>::MaxHeap(){
    size = 1;//size starts as 1 because 0th node is a sentinel
    capacity = DEFAULT_MAXHEAP_CAPACITY;
    priorityQueue.resize(capacity);
    priorityQueue.at(0) = T();//sentinel
    priorityQueue.at(0).assignMaximumPriority();//sentinel always equal to max priority
  }

  template <typename T>
  MaxHeap<T>::MaxHeap(int capacity) {
    size = 1;
    this->capacity = capacity;
    priorityQueue.resize(capacity);
    priorityQueue.at(0) = T();
    priorityQueue.at(0).assignMaximumPriority();
  }

  template <typename T>
  MaxHeap<T>::MaxHeap(std::vector<T> items, int n) {
    size = 1;
    capacity = n + 1;
    //priorityQueue.resize(capacity);
    priorityQueue.push_back(T());
    priorityQueue.at(0).assignMaximumPriority();
    for (int i = 0; i < n; i++) {
      priorityQueue.push_back(items[i]);
      size++;
    }
    int lastParentIndex = (size-1)/2;
    for (int i = lastParentIndex; i > 0; i--) {
      percolateDown(i);
  }
}

/*LOGIC******************************************************************************/
  template <typename T>
  T MaxHeap<T>::serve() {//removes the front item from the PQ, fixes the structure, and returns that item
    if (size == 1) return T();//PQ empty
    T served = priorityQueue.at(1);//saves the item pointer for returning
    priorityQueue.at(1) = priorityQueue.at(size-1);//move last element to the top and percolate down
    size--;
    percolateDown(1);
    return served;
  }

  template <typename T>
  bool MaxHeap<T>::insert(T item) {//inserts a customer into the maxheap, returns true if successful
    if (size >= capacity) return false;//PQ full
    priorityQueue.at(size) = item;//insert at the bottom, percolate up
    percolateUp(size);
    size++;
    return true;
  }

  template <typename T>  
  void MaxHeap<T>::percolateUp(int index) {
    int parentIndex = parent(index);
    T curr = priorityQueue.at(index);
    T currParent = priorityQueue.at(parentIndex);

    while (curr > currParent){//curr can never be greter than element 0
      swap(index, parentIndex);//keep swapping while parents have lower priority
      index = parentIndex;
      parentIndex = parent(index);
      currParent = priorityQueue.at(parentIndex);
    }
  }

  template <typename T>
  void MaxHeap<T>::percolateDown(int index) {
    T curr = priorityQueue.at(index);
    while (index <= (size-1)/2) {//nodes below size/2 have children
      //keep swapping while a child has higher priority
      int lChildIndex = LChild(index);
      T lChild = priorityQueue.at(lChildIndex);
      if ((index * 2 + 1) == size) {//node only has left child
        if (lChild > curr) swap(index, lChildIndex);
        return;
      }
      else {//node has 2 children
        int rChildIndex = RChild(index);
        T rChild = priorityQueue.at(rChildIndex);
        if (curr > lChild && curr > rChild) return;//curr has higher priority than its children
        if (lChild > rChild) {//left child has highest priority among the 3
          swap(index, lChildIndex);
          index = lChildIndex;
        }
        else {//right child must have highest priority
          swap(index, rChildIndex);
          index = rChildIndex;
        }
      }
    }
  }

/*HELPERS******************************************************************************/
  template <typename T>
  int MaxHeap<T>::parent(int index) const {return index/2;}

  template <typename T>
  int MaxHeap<T>::LChild(int index) const {return index*2;}

  template <typename T>
  int MaxHeap<T>::RChild(int index) const {return index*2 + 1;}

  template <typename T>
  void MaxHeap<T>::swap(int indexA, int indexB) {//swaps 2 customers positions
    std::swap(priorityQueue.at(indexA), priorityQueue.at(indexB));
  }

/*GETTERS******************************************************************************/
  template <typename T>
  bool MaxHeap<T>::isEmpty() const {
    if (size <= 1) return true;//1 based 
    else return false;
  }

  template <typename T>
  T MaxHeap<T>::retrieve() const {return priorityQueue.at(1);}//returns the top item without modifying

  template <typename T>
  int MaxHeap<T>::getSize() const {return size;}
  
  /*template <typename T>
  void MaxHeap<T>::print() const {
    for (int i = 0; i < size; i++) {
      std::cout << priorityQueue[i].getPriority() << std::endl;
    }
  }*/
#endif