#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_set>
#include <iostream>
using namespace std;
unordered_set<int> visited;

bool isExhausted(int currentNode, unordered_map<int, vector<int>> graph)
{
    // if already visited
    if(visited.count(currentNode)>0)
    {
        return false;
    }
    // if not yet visited
    visited.insert(currentNode);
    // traverse it all adjacency node
    for(int node: graph[currentNode])
    {
       isExhausted(node, graph);
    }
    // if the that connected Component is all traversed and exhausted
    return true;
}
int connectedComponentsCount(unordered_map<int, vector<int>> graph) {
  // todo
  
  int count=0;

    // if current Node is non-visited node
  // O(e)
  // passing the each node of the graph
  // 
  for(auto edge: graph)
  {   
      if(isExhausted(edge.first, graph))
        count++;
  }
  
  return count;

}



void run() {
 std::unordered_map<int, std::vector<int>> graph {
  { 3, { } },
  { 4, { 6 } },
  { 6, { 4, 5, 7, 8 } },
  { 8, { 6 } },
  { 7, { 6 } },
  { 5, { 6 } },
  { 1, { 2 } },
  { 2, { 1 } }
};

int n = connectedComponentsCount(graph); // -> 3
cout<<"There is a "<<n<< " connected component!";
}

int main()
{
    run();
}