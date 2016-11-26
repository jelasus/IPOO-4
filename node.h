#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef int number;
template<class T>
class Node{
public:
  T val;
  Node<T>* next;
  Node();
  Node(const T& );
};
template<class T>
class cNode: public Node<T>{
public:
  cNode<T>* prev;
  T val;
  cNode<T>* next;
  cNode();
  cNode(const T& );
};
template<class T>
class Linked_list: public Node<T>{
protected:
  Node<T>* head;
  Node<T>* tail;
public:
  Linked_list();
  Linked_list(Node<T>* );
  void ll_add_head(Node<T>* );
  void ll_add_tail(Node<T>* );
  Node<T>* ll_get_head();
  Node<T>* ll_get_tail();
  friend ostream& operator<<(ostream& output, const Linked_list<T>& o){
    Node<T>* cur=o.head;
    while(cur!=NULL){
      output << cur->val << endl;
      cur=cur->next;
    }
    return output;
  }
  void ll_remove(T);
  number _size();
};
template<class T>
class Linked_circular_list: public Linked_list<T>{
public:
  using Linked_list<T>::Linked_list;
  void lcl_add_head(Node<T>* );
  void lcl_add_current(Node<T>* );
  friend ostream& operator<<(ostream& output, const Linked_circular_list<T>& o){
    Node<T>* temp=o.head;
    while(temp->val!=o.tail->val)
    {
      cout << temp->val << endl;
      temp=temp->next;
    }
    if (o.tail!=NULL)
      cout << o.tail->val << endl;
  }
  //metodos get iguales a Linked_list
};

template<class T>
class Double_linked_list: public cNode<T>{
protected:
  cNode<T>* head;
  cNode<T>* tail;
public:
  Double_linked_list();
  Double_linked_list(cNode<T>* );
  void dll_add_head(cNode<T>* );
  void dll_add_tail(cNode<T>* );
  cNode<T>* dll_get_head();
  cNode<T>* dll_get_tail();
  friend ostream& operator<<(ostream& output, const Double_linked_list<T>& o){
    cNode<T>* temp=o.head;
    while(temp->val!=o.tail->val)
    {
      cout << temp->val << endl;
      temp=temp->next;
    }
    if(o.tail)
    cout << o.tail->val << endl;
  }
  number _size();
};
template <class T>
class Double_linked_circular_list: public Double_linked_list<T>{
public:
  using Double_linked_list<T>::Double_linked_list;
  void dlcl_add_head(cNode<T>* );
  void dlcl_add_tail(cNode<T>* );
};
template<class T>
class _stack: public Linked_list<T>{
public:
  using Linked_list<T>::Linked_list;
  void _push_back(Node<T>* );
  T _pop();
};
template<class T>
class _queue: public Linked_circular_list<T>{
public:
  using Linked_circular_list<T>::Linked_circular_list;
  void _push_back(Node<T>* );
  T _pop();
  bool Empty();
};

template<class T>
class queue_priority: public _queue<T>{
  map<number, _queue<T>> Pqueue;
  vector<number> vecpri;
  void bubble();
public:
  queue_priority() {}
  void Push_back(Node<T>* , const number );
  T Pop();
};

#endif // NODE_H
