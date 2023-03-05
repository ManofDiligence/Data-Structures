#include <iostream>
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
}