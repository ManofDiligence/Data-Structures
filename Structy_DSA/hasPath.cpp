#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
bool hasPath(unordered_map<string,vector<string>> graph, string src, string dst) {
  // todo
  // use src node and its adjacency list to traverse to the dst node
  // bfs or dfs to traverse the graph
  queue<string> Q;
  Q.push(src);
  while(Q.size())
  {
    string current = Q.front();
    Q.pop();
    if(current==dst) return true;
    for(string node: graph[current])
        Q.push(node);
  }
  
  return false;
}



void run() {
  unordered_map<string, vector <string>> graph{
  { "f", {"g", "i"} },
  { "g", {"h"} },
  { "h", {} },
  { "i", {"g", "k"} },
  { "j", {"i"} },
  { "k", {} }
};

bool hasAPath = hasPath(graph, "f", "k"); // 1 (true)
if(hasAPath) cout<<"It does has a path!";
else cout<<"It doesn't has a path!";
}

int main()
{
    run();
}