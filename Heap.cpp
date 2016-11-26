#include "Heap.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <math.h>
using namespace std;

Heap::Heap(): _size(0) {}
void Heap::Push_back(const NUMBER& node){
  this->Array.push_back(node);
  ++this->_size;
  Fix(_size-1);
}
NUMBER Heap::Remove_smallest(){
  NUMBER node=0;
  if (_size>0){
    node=this->Array[0];
    this->Array[0]=this->Array[_size-1];
    this->Array.pop_back();
  }
  else
    throw invalid_argument("No hay mas elementos por eliminar \n");
  --this->_size;
  return node;
}
void MaxHeap::Fix(NUMBER index){
  if ((this->Array[index] > this->Array[ceil((index-1)/2)]) && (index!=0)){
    NUMBER temp;
    temp=this->Array[index];
    this->Array[index] = this->Array[ceil((index-1)/2)];
    this->Array[ceil((index-1)/2)] = temp;
    Fix(ceil((index-1)/2));
  }
  else
    return;
}
void MinHeap::Fix(NUMBER index){
  if ((this->Array[index] < this->Array[ceil((index-1)/2)]) && (index!=0)){
    NUMBER temp;
    temp=this->Array[index];
    this->Array[index] = this->Array[ceil((index-1)/2)];
    this->Array[ceil((index-1)/2)] = temp;
    Fix(ceil((index-1)/2));
  }
  else
    return;
}
NUMBER Heap::Get_node(NUMBER index){
  if (index>=0 && index<this->Array.size())
    return this->Array[index];
  else{
    throw invalid_argument("Index out of scope \n");
    return -1;
  }
}


main(){
  MinHeap M1;
  M1.Push_back(10);
  M1.Push_back(20);
  M1.Push_back(15);
  M1.Push_back(16);
  cout << M1.Get_node(1);
  return 0;
}
