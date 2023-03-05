#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <limits>
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

int sum=0;
int maxPathSum(Node* root) {
  // todo
  // base case is null node
  // for any node have right child but no left child 
  // or have left child but not right child
  // case1: base case: null node
  if(root==nullptr) {
    return numeric_limits<int>::min();
  }
  // case 2: base case: leaf node
  else if(root->left==nullptr&&root->right==nullptr) 
  {
    return root->val;
  }
  // case 3: node have right child and left child 
  else {
    sum=root->val+max(maxPathSum(root->left), maxPathSum(root->right));
  }   
  
  return sum;
}


void run() {
  Node a(-1);
Node b(-6);
Node c(-5);
Node d(-3);
Node e(0);
Node f(-13);
Node g(-1);
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
// -3   0    -13
//     /       \
//    -1       -2

int max = maxPathSum(&a); // -> -8
cout<<"Max path sum from root to leaf of this tree is "<<max;
}

int main()
{
    run();
}