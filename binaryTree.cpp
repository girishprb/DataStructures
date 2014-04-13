#include<stdlib.h>
#include<iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *left;
	Node *right;

	Node(int val)
	{
		value = val;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree
{
public:
	Node *root;

	BinaryTree()
	{
		root = NULL;
	}

	//Searches the tree to check if the specified value exists
	bool Lookup(int val);

	//Inserts value depending on the value (BST)
	Node * Insert(Node *node, int val);

	//Initialize the tree with specified size and range(optional)
	void Initialize(int size, int min = 0, int max = 100);
};

bool BinaryTree::Lookup(int val)
{
	bool result = false;
	//TODO: something similiar to inorder traversal unitl a match is found or all nodes are traversed.

	return result;
}

Node * BinaryTree::Insert(Node *node, int val)
{
	if(node == NULL)
	{
		Node *newNode = new Node(val);
		return newNode;
	}
	else
	{
		if(val <= node->value)
			node->left = Insert(node->left, val);
		else
			node->right = Insert(node->right, val);
		return node;
	}
}

void BinaryTree::Initialize(int size, int min, int max)
{
	root = NULL;
	int val;
	for(int i=0; i<size; i++)
	{
		val = min + (rand() % (int)(max + min));
		root = Insert(root, val);
		cout<<"Inserted "<<val<<endl;

	}
}

/*-----------Global functions----------------*/

//Inorder Traversal
void InOrder(Node *node)
{
	if(node == NULL)
		return;
	
	InOrder(node->left);
	cout<<node->value<<"\t";
	InOrder(node->right);
}

//Postorder Traversal
void PostOrder(Node *node)
{
	if(node == NULL)
		return;

	PostOrder(node->left);
	PostOrder(node->right);
	cout<<node->value<<"\t";
}

//PreOrder Traversal
void PreOrder(Node *node)
{
	if(node == NULL)
		return;
	cout<<node->value<<"\t";
	PostOrder(node->left);
	PostOrder(node->right);
}

//Check if the given tree is a Binary search tree
bool IsTreeBST(Node *root)
{
	bool result = false;

	return result;
}


int main()
{
	BinaryTree binaryTree;
	binaryTree.Initialize(10);
	cout<<endl<<"Inorder:";
	InOrder(binaryTree.root);
	cout<<endl<<"Preorder:";
	PreOrder(binaryTree.root);
	cout<<endl<<"Postorder:";
	PostOrder(binaryTree.root);
	cout<<endl;


	return 0;
}





