#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Node {
  public:
    string val;
    Node* left;
    Node* right;


    Node(string initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};



vector<string> dfsTree;
vector<string> emptyTree;
vector<string> depthFirstValues(Node* root) {
  
  if(root==nullptr) return emptyTree;
  // get the element
  dfsTree.push_back(root->val);
  depthFirstValues(root->left);
  depthFirstValues(root->right);
  return dfsTree;
}
void print(vector<string> tree)
{
    for(int i=0;i <tree.size(); i++)
    {
        cout<<tree[i]<<" ";
    }
}

void run() {
  Node a("a");
Node b("b");
Node c("c");
Node d("d");
Node e("e");
Node f("f");
Node g("g");

a.left = &b;
a.right = &c;
b.left = &d;
b.right = &e;
c.right = &f;
e.left = &g;

//      a
//    /   \
//   b     c
//  / \     \
// d   e     f
//    /
//   g
vector<string> tree;
tree = depthFirstValues(&a); 
//    -> ["a", "b", "d", "e", "g", "c", "f"]
print(tree);
}

int main()
{
    run();
}