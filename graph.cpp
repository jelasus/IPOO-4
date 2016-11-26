#include "graph.h"
#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
using namespace std;

Graph::Graph(const vector<NODE>& starts, const vector<NODE>& ends){
  if (starts.size()!=ends.size())
    throw invalid_argument("vectores stars/end don't have the same size \n");
  else
    for(int i=0;i<starts.size();i++){
      this->Adjacency_list[starts[i]].push_back(ends[i]);
      this->Adjacency_list[ends[i]];
    }
}
NODE Graph::numOutgoing(const NODE nodeID) const{
  return adjacent(nodeID).size();
}
const vector<NODE>& Graph::adjacent(const NODE nodeID) const{
  map<NODE,vector<NODE>>::const_iterator it;
  it = this->Adjacency_list.find(nodeID);
  if (it==this->Adjacency_list.end()){
    throw invalid_argument("Node doesn't found \n");
  }
  return it->second;
}

main(){
  vector<NODE> a;
  vector<NODE> b;
  a.push_back(1);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(3);
  b.push_back(2);
  b.push_back(3);
  b.push_back(2);
  b.push_back(1);
  b.push_back(4);
  Graph mygraph(a,b);
  NODE i = mygraph.numOutgoing(5);
  cout << i ;
  return 0;
}

