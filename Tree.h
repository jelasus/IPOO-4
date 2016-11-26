#ifndef TREE_H
#define TREE_H

typedef int number;

struct Node{
  number value;
  Node* right;
  Node* left;
  Node* parent;
};

class Tree{
  number childs;
  Node* root;
  void Insert(number, Node* );
  void Print_tree(Node* );
public:
  Tree();
  ~Tree();
  void Delete_tree(Node* );
  void Insert(number);
  void Print_tree();
};

#endif // TREE_H
