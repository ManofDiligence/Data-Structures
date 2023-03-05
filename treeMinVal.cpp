#include <iostream>
#include <queue>
using namespace std;
class Node {
  public:
    int val;
    Node* left;
    Node* right;


    Node(int initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};



int treeMinValue(Node* root) {
  // todo
  queue<Node*> findMinQueue;
  int min=root->val;
  findMinQueue.push(root);
  while(findMinQueue.size())
  {
      Node* temp = findMinQueue.front();
      if(temp->val<min) min = temp->val;
      if(temp->left!=nullptr) findMinQueue.push(temp->left);
      if(temp->right!=nullptr) findMinQueue.push(temp->right);
      findMinQueue.pop();
  }
  return min;
}


void run() {
  Node a(-1);
Node b(-6);
Node c(-5);
Node d(-3);
Node e(-4);
Node f(-13);
Node g(-2);
Node h(-2);

a.left = &b;
a.right = &c;
b.left = &d;
b.right = &e;
c.right = &f;
e.left = &g;
f.right = &h;

//        -1
//      /   \
//    -6    -5
//   /  \     \
// -3   -4   -13
//     /       \
//    -2       -2
int min = treeMinValue(&a); // -> -13
cout<<"Min value of this tree is "<<min;
}

int main()
{
    run();
}