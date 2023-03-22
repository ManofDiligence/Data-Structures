#include <cstddef>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* getNewNode(int data)
{
        BstNode* newNode = new BstNode();
        newNode->left = newNode->right = NULL;
        newNode->data = data;
        return newNode;
}
BstNode* Insert(BstNode* root, int data)
{
    // if it is empty tree
    // create a new root node for the tree
    if(root==NULL)
    {
        root = getNewNode(data);
    }
    // recursive case 
    else if(root->data>=data)
    {
        root->left=Insert(root->left, data);
    }
    else
    {
        root->right=Insert(root->right, data);
    }
    return root;

}

bool search(BstNode* root, int data)
{
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(root->data>data)
    {
        return search(root->left, data);
    }
    else 
    {
       return search(root->right, data);
    }
}
int findMax(BstNode* root)
{
    // if the tree is empty
    if(root==NULL) 
    {
        cout<<"Error: The tree is empty";
        return -1;
    }
    // if the tree is no empty
    if(root->right==NULL) return root->data;
    else return findMax(root->right);

}
int findMin(BstNode* root)
{
    // if the tree is empty
    if(root==NULL) 
    {
        cout<<"Error: The tree is empty";
        return -1;
    }
    // if the tree is not empty
    if(root->left==NULL) return root->data;
    else return findMin(root->left);
}
// Stack
void DFS_Stack_preorder(BstNode* root)
{
    stack<BstNode*> s;
    if(root==nullptr) return; 
    s.push(root);
    while(!s.empty())
    {
        BstNode* cur = s.top();
        s.pop();
        cout<<cur->data<<" ";
        if(cur->right!=nullptr)
            s.push(cur->right);
        if(cur->left!=nullptr)
            s.push(cur->left);   
    }
}
void DFS_Stack_inorder(BstNode* root)
{
    stack<BstNode*> s;
    if(root==nullptr) return; 
    BstNode* curNode = root;
    while(!s.empty()||curNode!=nullptr)
    {
        // if have left child, push it to stack
        while(curNode!=nullptr)
        {
            s.push(curNode);
            curNode=curNode->left;
        }
        curNode = s.top();
        s.pop();
        cout<<curNode->data<<" ";
        curNode = curNode->right;
        
    }
}
void DFS_Stack_postorder(BstNode* root)
{
    if (root == NULL) {
        return;
        }
        stack<BstNode*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            BstNode* current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left) {
                s1.push(current->left);
            }
            if (current->right) {
                s1.push(current->right);
            }
        }
        while (!s2.empty()) {
            BstNode* current = s2.top();
            cout << current->data << " ";
            s2.pop();
        }
        cout << endl;
}

// Recursion
// use the call stack to implement dfs' preorder
// preorder = <root><left><right>
void dfs_preorder(BstNode* root)
{
    if(root==nullptr) return; 
    cout<<root->data<<" ";
    dfs_preorder(root->left);
    dfs_preorder(root->right);
}
// inorder = <left><root><right>
void dfs_inorder(BstNode* root)
{   
    if(root==nullptr) return;
    dfs_inorder(root->left);
    cout<<root->data<<" ";
    dfs_inorder(root->right);
    
}
// postorder = <left><right><root>
void dfs_postorder(BstNode* root)
{
    if(root==nullptr) return;
    dfs_postorder(root->left);
    dfs_postorder(root->right);
    cout<<root->data<<" ";
   
}
void bfs_order(BstNode* root)
{
    if(root==nullptr) return; 
    queue<BstNode*> q;
    q.push(root);
    while(!q.empty())
    {
        BstNode* curNode = q.front();
        cout<<curNode->data<<" ";
        if(curNode->left!=nullptr)
            q.push(curNode->left);
        if(curNode->right!=nullptr)
            q.push(curNode->right);
        q.pop();
    }
    cout<<"\n";
}
int findHeight(BstNode* root)
{
    // if empty tree
    if(root==NULL) return -1;
    // if the node is leaf node, return the height
    if (root->left==NULL&&root->right==NULL)
        return 0;
    // if the node is not leaf, keep diving deeply
    int rightHeight = findHeight(root->right);
    int leftHeight = findHeight(root->left);

    return 1+ max(rightHeight, leftHeight);
}
/* bool isSubtreeLesser(BstNode* root, int value)
{
    if(root==nullptr) return true;
    if(root->data<=value&&isSubtreeLesser(root->left, value)
        &&isSubtreeLesser(root->right, value))
    {
        return true;
    }
    return false;
}
bool isSubtreeGreater(BstNode* root, int value)
{
    if(root==nullptr) return true;
    if(root->data>value&&isSubtreeGreater(root->left, value)
        &&isSubtreeGreater(root->right, value))
    {
        return true;
    }
    return false;
}
bool isBinarySearchTree1(BstNode* root)
{
    if (root==nullptr) return true;
    if(isSubtreeGreater(root->right, root->data)&&
       isSubtreeLesser(root->left, root->data)&&
       isBinarySearchTree1(root->left)&&
       isBinarySearchTree1(root->right))
       return true;
    else return false;
} */
bool isBstUtil(BstNode* root, int minValue, int maxValue)
{
    if(root==nullptr) return true;
    if(root->data>minValue&&root->data<maxValue
    &&isBstUtil(root->left, minValue, root->data)
    &&isBstUtil(root->right, root->data, maxValue))
        return true;
    else return false;
    
}
bool isBinarySearchTree(BstNode* root)
{
    return isBstUtil(root, INT_MIN, INT_MAX);
}
BstNode* Delete(BstNode* root, int data)
{
    
}
int main()
{
    BstNode* root = NULL;
    root = Insert(root, 27);
	root = Insert(root, 12);
	root = Insert(root, 30);
	root = Insert(root, 33);
	root = Insert(root, 15);
	root = Insert(root, 8);
    int data = 3;
    if(search(root, data)) cout<<data<<" is found!";
    else cout<<data<<" is not found";
    
    cout<<"\nThe max value in this tree is: "<<findMax(root);
    cout<<"\nThe min value in this tree is: "<<findMin(root);
    cout<<"\nThe height of tree is: "<<findHeight(root);
    cout<<"\nThe BFS traversal order of the tree: ";
    bfs_order(root);
    cout<<"\nThe DFS preorder of the tree: ";
    dfs_preorder(root);
    cout<<"\nThe DFS inorder of the tree: ";
    dfs_inorder(root);
    cout<<"\nThe DFS postorder of the tree: ";
    dfs_postorder(root);
    cout<<"\nThe DFS preorder using stack of the tree: ";
    DFS_Stack_preorder(root);
    cout<<"\nThe DFS inorder using stack of the tree: ";
    DFS_Stack_inorder(root);
    cout<<"\nThe DFS postorder using stack of the tree: ";
    DFS_Stack_postorder(root);
    if(isBinarySearchTree(root)) cout<<"It is a BST!";
    else cout<<"It is not a BST.";
    return 0;
}
