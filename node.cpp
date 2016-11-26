#include "node.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;
////////////////NODE///////////////////
template<class T>
Node<T>::Node(): val(), next() {}
template<class T>
Node<T>::Node(const T& Val): val(Val), next(NULL) {}
////////////////cNode//////////////////
template<class T>
cNode<T>::cNode(): val(), next(), prev() {}
template<class T>
cNode<T>::cNode(const T& Val): val(Val), next(NULL), prev(NULL) {}
///////////LINKED_LIST////////////////
template<class T>
Linked_list<T>::Linked_list(): head(NULL), tail(NULL){}
template<class T>
Linked_list<T>::Linked_list(Node<T>* lnode): head(lnode), tail(lnode){}
template<class T>
void Linked_list<T>::ll_add_head(Node<T>* lnode){
  lnode->next=this->head;
  head=lnode;
}
template<class T>
void Linked_list<T>::ll_add_tail(Node<T>* lnode){
  this->tail->next=lnode;
  tail=lnode;
}
template<class T>
Node<T>* Linked_list<T>::ll_get_head() {return this->head;}
template<class T>
Node<T>* Linked_list<T>::ll_get_tail() {return this->tail;}
template<class T>
void Linked_list<T>::ll_remove(T key){
  Node<T>* cur;
  Node<T>* pre;
  Node<T>* temp;
  if (key==head->val){
    temp=head;
    delete this->head;
    this->head=temp;
    return;
  }
  pre=this->head;
  cur=this->head->next;
  while (cur!=NULL){
    if (key==cur->val){
      pre->next=cur->next;
      delete cur;
      break;
      }
    pre=cur;
    cur=cur->next;
    if (cur->val==this->tail->val)
      this->tail=pre;
  }
}
template<class T>
number Linked_list<T>::_size(){
  number i;
  Node<T>* temp=this->head;
  for(i=0;temp!=NULL;i++)
    temp=temp->next;
  return i;
}
//////////Linked_circular_list///////////
template<class T>
void Linked_circular_list<T>::lcl_add_head(Node<T>* lnode){
  lnode->next=this->head;
  this->head=lnode;
  this->tail->next=lnode;
}
template<class T>
void Linked_circular_list<T>::lcl_add_current(Node<T>* lnode){
  lnode->next=this->head;
  this->tail->next=lnode;
  this->tail=lnode;
}
/////////////Double_linked_list/////////////////
template<class T>
Double_linked_list<T>::Double_linked_list(): head(), tail() {}
template<class T>
Double_linked_list<T>::Double_linked_list(cNode<T>* lnode): head(lnode), tail(lnode) {};
template<class T>
void Double_linked_list<T>::dll_add_head(cNode<T>* lnode){
  lnode->next=this->head;
  this->head->prev=lnode;
  this->head=lnode;
}
template<class T>
void Double_linked_list<T>::dll_add_tail(cNode<T>* lnode){
  this->tail->next=lnode;
  lnode->prev=this->tail;
  this->tail=lnode;
}
template<class T>
cNode<T>* Double_linked_list<T>::dll_get_head() {return this->head;}
template<class T>
cNode<T>* Double_linked_list<T>::dll_get_tail() {return this->tail;}
template<class T>
number Double_linked_list<T>::_size(){
  number i;
  Node<T>* temp;
  while (temp->val!=this->tail->val){
    temp=temp->next;
    ++i;
  }
  return i+1;
}
///////////Double_linked_circular_list///////////
template <class T>
void Double_linked_circular_list<T>::dlcl_add_head(cNode<T>* lnode){
  lnode->next=this->head;
  this->head->prev=lnode;
  this->head=lnode;
  this->tail->next=lnode;
  lnode->prev=this->tail;
}
template <class T>
void Double_linked_circular_list<T>::dlcl_add_tail(cNode<T>* lnode){
  this->tail->next=lnode;
  lnode->prev=this->tail;
  this->tail=lnode;
  lnode->next=this->head;
  this->head->prev=lnode;
}
///////////////STACK///////////////
template<class T>
void _stack<T>::_push_back(Node<T>* lnode){
  lnode->next=this->head;
  this->head=lnode;
}
template<class T>
T _stack<T>::_pop(){
  T Val=this->head->val;
  Node<T>* temp;
  temp=this->head->next;
  delete this->head;
  this->head=temp;
  return Val;
}
///////////////QUEUE//////////////
template<class T>
void _queue<T>::_push_back(Node<T>* lnode){
  lnode->next=this->head;
  this->tail->next=lnode;
  this->tail=lnode;
}
template<class T>
T _queue<T>::_pop(){
  Node<T>* temp;
  T Val=this->head->val;
  temp=this->head->next;
  this->tail->next=temp;
  delete this->head;
  this->head=temp;
  return Val;
}
template<class T>
bool _queue<T>::Empty(){
  if (this->tail==NULL)
    return false;
  else
    return true;
}
///////////Queue_Priority////////
template<class T>
void queue_priority<T>::Push_back(Node<T>* lnode, const number priority){
  for (number i=0; i<this->vecpri.size();i++){
    if (priority==this->vecpri[i]){
      this->Pqueue[priority]->head=lnode;
      this->Pqueue[priority]->tail=lnode;
    }
    else
      this->Pqueue[priority]._push_back(lnode);
  }
  for (number i=0; i<this->vecpri.size();i++)
    if (priority==this->vecpri[i])
      return;
  vecpri.push_back(priority);
}
template<class T>
T queue_priority<T>::Pop(){
  bubble();
  for (number i=0; i<this->vecpri.size(); i++){
    if (this->Pqueue[this->vecpri[i]].Empty())
      return this->Pqueue[this->vecpri[i]]._pop();
  }
}
template<class T>
void queue_priority<T>::bubble(){
  for (number i=0; i<this->vecpri.size();i++)
    for (number j=0; i<this->vecpri.size()-i-1; j++)
      if(this->vecpri[j]>this->vecpri[j+1]){
        T temp;
        temp=this->vecpri[i];
        this->vecpri[j]=this->vecpri[j+1];
        this->vecpri[j+1]=temp;
      }
}

main(){
  Linked_list<int> l1(new Node<int>(6));
  l1.ll_add_head(new Node<int>(5));
  l1.ll_add_tail(new Node<int>(7));
  cout << l1;
  Linked_circular_list<int> l2(new Node<int>(2));
  l2.lcl_add_head(new Node<int>(1));
  Node<int>* p = l2.ll_get_tail();
  cout << p->next->val << endl;//demuestro que l2 es una lista circular enlazada
  cout << l2;
  Double_linked_circular_list<int> l3(new cNode<int>(10));
  l3.dlcl_add_head(new cNode<int>(9));
  l3.dlcl_add_tail(new cNode<int>(11));
  cout << l3;
  cNode<int>* q = l3.dll_get_tail();
  cout << q->next->val << endl; //demuestro que es una lista doble circular enlazada
  _queue<char> l4(new Node<char>('C'));
  l4._push_back(new Node<char>('D'));
  l4._push_back(new Node<char>('E'));
  cout << l4._pop();
  l4._push_back(new Node<char>('F'));
  cout << l4._pop();
  queue_priority<int> q1;
  q1.Push_back(new Node<int> (5), 2);
  return 0;
}
