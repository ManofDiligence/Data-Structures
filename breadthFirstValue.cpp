#include <string>
#include <vector>
#include <queue>
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


vector<string> bfsTree;
queue<Node*> bfsQueue;
vector<string> breadthFirstValues(Node* root) {
  
  if(root==nullptr) return bfsTree;
  else if(root->left==nullptr&&root->right==nullptr) {bfsTree.push_back(root->val);return bfsTree;}
  
    bfsQueue.push(root);
    while(bfsQueue.front()!=nullptr)
    {
      // get first element

        Node* temp = bfsQueue.front();
      //del the first

        bfsQueue.pop();
        if(temp->left!=nullptr) bfsQueue.push(temp->left);
        if(temp->right!=nullptr) bfsQueue.push(temp->right);
        bfsTree.push_back(temp->val);

    }
    return bfsTree;
  
  
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
Node x("x");

a.right = &b;
b.left = &c;
c.left = &x;
c.right = &d;
d.right = &e;

//      a
//       \
//        b
//       /
//      c
//    /  \
//   x    d
//         \
//          e
vector<string> tree;
tree = breadthFirstValues(&a);
//    -> ["a", "b", "c", "x", "d", "e"]
 print(tree);
}
int main()
{
    run();
}