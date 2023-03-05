#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
unordered_set<int> visited;
int len=0;
int lengthOfComponent(int currentNode, unordered_map<int ,vector<int>> graph)
{
    // if already visited this currentNode
    if(visited.count(currentNode)>0) 
        return 0;
    // if not yet visited this currentNode
    visited.insert(currentNode);
    // each time traverse each node of that component
    len++;
    // traverse all the node of that adjacency list
    for(int node: graph[currentNode])
    {
      lengthOfComponent(node, graph);
    }
    // after traverse all the connected node
    // return each connected component's size
    return len;
}

int largestComponent(unordered_map<int, vector<int>> graph) {
  // todo
  int maxLength = 0;

  for(auto edge: graph)
  {
      int otherLength=lengthOfComponent(edge.first, graph);
      if(otherLength>maxLength) maxLength = otherLength;
      // reset the component size for next component
      len=0;
  }
  return maxLength;
}



void run() {
  std::unordered_map<int, std::vector<int>> graph {
  { 0, {8, 1, 5} },
  { 1, {0} },
  { 5, {0, 8} },
  { 8, {0, 5} },
  { 2, {3, 4} },
  { 3, {2, 4} },
  { 4, {3, 2} }
};

int n = largestComponent(graph); // -> 4
cout<<"The size of largest component is "<< n;
}

int main()
{
    run();
}