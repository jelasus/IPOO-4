#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
using namespace std;

typedef int NUMBER;
typedef int COUNTER;

class Heap{
protected:
  COUNTER _size;
  vector<NUMBER> Array;
public:
  Heap();
  void Push_back(const NUMBER& );
  NUMBER Remove_smallest();
  virtual void Fix(NUMBER)=0;
  NUMBER Get_node(NUMBER);
};

class MaxHeap: public Heap{
  void Fix(NUMBER);
};

class MinHeap: public Heap{
  void Fix(NUMBER);
};

#endif // HEAP_H
