#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(): root(NULL),childs(0) {}
Tree::~Tree(){
  Delete_tree(this->root);
}
void Tree::Insert(number Value){
  if (this->root!=NULL)
    Insert(Value, this->root);
  else{
    this->root = new Node;
    this->root->value=Value;
    this->root->left=NULL;
    this->root->right=NULL;
  }
}
void Tree::Insert(number Value, Node* lnode){
  if (Value < lnode->value){
    if (lnode->left!=NULL)
      Insert(Value, lnode->left);
    else{
      lnode->left = new Node;
      lnode->left->value=Value;
      lnode->left->left=NULL;
      lnode->left->right=NULL;
    }
  }
  else if(Value >= lnode->value){
    if (lnode->right!=NULL)
      Insert(Value, lnode->right);
    else{
      lnode->right = new Node;
      lnode->right->value=Value;
      lnode->right->left=NULL;
      lnode->right->right=NULL;
    }
  }
}
void Tree::Delete_tree(Node* tnode){
  if (tnode!=NULL){
    Delete_tree(tnode->left);
    Delete_tree(tnode->right);
    delete tnode;
  }
}
void Tree::Print_tree(Node* lnode){
  if (lnode!=NULL){
    Print_tree(lnode->left);
    cout << lnode->value << endl;
    Print_tree(lnode->right);
  }
}
void Tree::Print_tree(){
  Print_tree(this->root);
}

main(){
  Tree t1;
  t1.Insert(2);
  t1.Insert(1);
  t1.Insert(14);
  t1.Insert(15);
  t1.Insert(90);
  t1.Print_tree();
  return 0;
}
