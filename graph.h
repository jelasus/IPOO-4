#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <vector>

using namespace std;

typedef int NODE;
typedef map<NODE, vector<NODE>> adjacency_list;

class Graph{
  adjacency_list Adjacency_list;
public:
  Graph(const vector<NODE>&, const vector<NODE>& );
  NODE numOutgoing(const NODE ) const;
  const vector<NODE>& adjacent(const NODE ) const;
};

#endif // GRAPH_H
