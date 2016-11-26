#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
bool Stack<T>::Empty(){
  if (this->STACK.size()==0)
    return true;
  else
    return false;
}
template<class T>
void Stack<T>::push(const T& item){
  this->STACK.push_back(item);
}
template<class T>
T& Stack<T>::top(){
  if (STACK.size()>0){
    T last=this->STACK[this->STACK.size()-1];
    return &last;
  }
  else
    return;
}
template<class T>
void Stack<T>::pop(){
  this->STACK.pop_back();
}

main(){
  Stack<int> list1;
  list1.push(1);
  list1.push(2);
  list1.push(3);
  Stack<int> list2;
  list2.push(3);
  list2.push(4);
  list1.pop();
  Stack<int> list3=list1+list2;
  cout << list3;
  return 0;
}
