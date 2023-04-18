#include <iostream>
#include <vector>
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
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
BstNode* Insert(BstNode* root, int data)
{
	// this is the so-called base case
	if (root == NULL) // empty tree 
	{
		root = getNewNode(data);
	}
	// these two else if is the recursive case
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}
bool Search(BstNode* root, int data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
	
}
int FindMin(BstNode* root)
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty\n";
		return -1;
	}
	
	/* Iterative approach
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
	*/
	// recursive approach 
	if (root->left == NULL) return root->data;
	return FindMin(root->left);
	
}

int FindMax(BstNode* root)
{
	if (root->right == NULL) return root->data;
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

int FindHeight(BstNode* root)
{
	// base case
	if (root == NULL) return -1;
	// recursive case
	int leftHeight = FindHeight(root->left);
	int rightHeight = FindHeight(root->right);

	return max(leftHeight, rightHeight) + 1;
}
// the baby for dynamic programming
int maxDepth1(BstNode* root) {
    if (root == nullptr) {
        return 0;
    }
    // recursion 計算左右子樹的最大深度
    // calculate max depth for left/right subtree
    int leftMax = maxDepth1(root->left);
    int rightMax = maxDepth1(root->right);
    // 整棵樹的最大深度
    // max depth for the whole tree
    int res = max(leftMax, rightMax) + 1;

    return res;
}
// to record the max depth
int res = 0;
int depth=0;
// the baby for backtracking
void traverse(BstNode* );

int maxDepth2(BstNode* root)
{
    traverse(root);
    return res;
}
// Binary tree traverse框架
void traverse(BstNode* root)
{
    if (!root) {
        res = max(res, depth);
        return;
    }

    // pre-order
    depth++;
    traverse(root->left);
    traverse(root->right);
    // post-order
    depth--;

}
int levelTraverse(BstNode* root)
{
    int Depth = 0;
    if(root==NULL) return Depth;
    queue<BstNode*> q;
    q.push(root);
    // 從上到下 traverse binary tree's each level
    while(!q.empty())
    {
        int numNode = q.size();
        // 從左到右 traverse 每一層的每個node
        for(int i=0; i<numNode; i++)
        {
            BstNode* current = q.front();
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
            q.pop();

        }
        Depth++;
    }
    return Depth;

}
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
// assum the level of root node is one
void traverseLevel(BstNode* root, int level)
{
	if(!root) return;
	cout<<root->data<<" is on "<<level<<endl;
	traverseLevel(root->left, level+1);
	traverseLevel(root->right, level+1);

}
int noOfNodesForLeftRight(BstNode* root)
{
	if(!root) return 0;
	int leftSub = noOfNodesForLeftRight(root->left);
	int rightSub = noOfNodesForLeftRight(root->right);
	cout<<root->data<<" have "<<leftSub<<" nodes in left and have "<< rightSub<<" nodes in right!"<<endl;

	return leftSub+rightSub+1;
}
int main()
{
	BstNode* root = NULL; // creating empty tree
	root = Insert(root, 27);
	root = Insert(root, 12);
	root = Insert(root, 30);
	root = Insert(root, 33);
	root = Insert(root, 15);
	root = Insert(root, 8);
	int n;
	cout << "Enter a number to be searched\n";
	cin >> n;
	if (Search(root, n)) cout << "Found\n";
	else cout << "Not Found\n";
	cout << "The min element of this tree is " << FindMin(root);
	cout << "\nThe max element of this tree is " << FindMax(root);
	cout << "\nThe height of tree is " << FindHeight(root);
    cout << "\nThe depth of the tree is "<<maxDepth2(root);
    cout << "\nThe depth of the tree is "<<levelTraverse(root);
	cout<<endl;
	traverseLevel(root, 1);
	cout<<endl;
	noOfNodesForLeftRight(root);
}