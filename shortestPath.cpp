#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// to insert the visited node
unordered_set<string> visited;
// for storing each node's cost
queue<tuple<string, int>> nodeDistance;
// for convert the list of edges to adjacency list
unordered_map<string, vector<string>> makeGraph(vector<tuple<string, string>> edges)
{
    unordered_map<string, vector<string>> graph;
    
    for(auto edge: edges)
    {
        // a = first node
        // b = second node 
        auto[a, b] = edge;
        // a is adjacent to b
        // b also adjacent to a
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return graph;
}  

int shortestPath(vector<tuple<string, string>> edges, string nodeA, string nodeB) {
  // todo
  // convert the list of edges of a adjacency list
  unordered_map<string, vector<string>> graph = makeGraph(edges);
  int shorterCost=0;
  string currentNode = nodeA;
  // {} is type of tuple
  nodeDistance.push({currentNode, shorterCost});
  // the starting node is visited
  visited.insert(currentNode);
  
  while(!nodeDistance.empty())
  {
      // get the node and the cost
      // auto is for all type, like python
      auto [currentNode, shorterCost] = nodeDistance.front();
      // another way to access tuple element
      //shorterCost = get<1>(front);
      //currentNode = get<0>(front);
      // if find the destination node
      if(currentNode==nodeB) return shorterCost;
      nodeDistance.pop();
      // visited the adjacent node
      for(string adj: graph[currentNode])
      {
        // if not yet visited
        if(visited.count(adj)==0) 
        {
          
          visited.insert(adj);
          // cost increase by 1 after move from node to node
          // similar to bfs
          nodeDistance.push({adj, shorterCost+1});
        } 
      }
  }
  if (shorterCost==0) return -1;
}



void run() {
  vector<tuple<string, string>> edges {
  {"m", "n"},
  {"n", "o"},
  {"o", "p"},
  {"p", "q"},
  {"t", "o"},
  {"r", "q"},
  {"r", "s"}
};
shortestPath(edges, "m", "s"); // -> 6
  vector<tuple<string, string>> edges1 {
  {"a", "c"},
  {"a", "b"},
  {"c", "b"},
  {"c", "d"},
  {"b", "d"},
  {"e", "d"},
  {"g", "f"}
};
shortestPath(edges1, "a", "e"); // -> 3
}