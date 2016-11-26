#ifndef STACK_H
#define STACK_H
#include <vector>
#include <iostream>
using namespace std;

typedef int number;

template<class T>
class Stack{
  vector<T> STACK;
public:
  bool Empty();
  void push(const T&);
  T& top();
  void pop();
  friend ostream& operator<<(ostream& output, const Stack<T>& o){
    for(number i=0;i<o.STACK.size();i++)
      output << o.STACK[i] << endl;
    return output;
  }
  friend Stack<T> operator+(Stack<T>& a,const Stack<T>& b){
    for(number i=0;i<b.STACK.size();i++)
      a.push(b.STACK[i]);
    return a;
  }
};

#endif // STACK_H
