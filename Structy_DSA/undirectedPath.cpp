#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std;

unordered_map<string, vector<string>> makeGraph (vector<tuple<string, string>> edges)
{
    unordered_map<string, vector<string>> graph;
    for(auto edge: edges)
    {
        auto[a, b]=edge;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }/*
    for(tuple<string, string> edge: edges)
    {
      string a = get<0>(edge);
      string b = get<1>(edge);
      graph[a].push_back(b);
      graph[b].push_back(a);
    }*/
  return graph;
}
bool explore(unordered_map<string, vector<string>> graph, string src, string dst, unordered_set<string> visited)
{
    if(src==dst) return true;  
    if(visited.count(src)>0)
    {
       return false;
    }
    visited.insert(src);
    for(string neighbor: graph[src])
    {
      if(explore(graph, neighbor, dst, visited)) return true;
    }
   
    return false;
}
bool undirectedPath(vector<tuple<string, string>> edges, string src, string dst) {

  unordered_map<string, vector<string>> graph = makeGraph(edges);
  unordered_set<string> visited;
  
  return explore(graph, src, dst, visited);
}


void run() {
  std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

bool hasAPath = undirectedPath(edges, "m", "j"); // -> 1 (true)
if(hasAPath) cout<<"It does has a path in this undirected graph!";
else cout<<"It doesn't has a path in this undirected graph!";
}
int main()
{
    run();
}