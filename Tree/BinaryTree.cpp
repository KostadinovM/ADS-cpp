#include <iostream>

using namespace std;


struct node
{
	int key_value;
	node *left;
	node *right;
};

class BinaryTree
{
public: 
	BinaryTree();
	void insert(int key);
	node* search(int key);
	void destroy();
	node* invert();

private:
		void destroy(node *leaf);
		void insert(int key, node *leaf);
		node *search(int key, node *leaf);
		node* invert(node *leaf);

		node *root;
};

BinaryTree::BinaryTree()
{
	root = nullptr;
}

void BinaryTree::destroy(node *leaf)
{
	if (leaf != nullptr)
	{
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}

void BinaryTree::destroy()
{
	destroy(root);
}

void BinaryTree::insert(int key, node* leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->left != nullptr)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (key > leaf->key_value)
	{
		if (leaf->right != nullptr)
			insert(key, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}

void BinaryTree::insert(int key)
{
	if (root != nullptr)
		insert(key, root);
	else
	{
		root = new node;
		root->key_value = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

node* BinaryTree::search(int key, node *leaf)
{
	if (leaf != nullptr)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else
		return nullptr;
}

node* BinaryTree::search(int key)
{
	return search(key, root);
}

node* BinaryTree::invert(node *leaf)
{
	if (leaf != nullptr)
	{
		node *right = invert(leaf->right);
		node *left = invert(leaf->left);
		leaf->left = right;
		leaf->right = left;
	}
	else
		return nullptr;
	
}

node* BinaryTree::invert()
{
	return invert(root);
}

void printPostorder(node *leaf)
{
	if (leaf == nullptr)
		return;
	printPostorder(leaf->left);
	printPostorder(leaf->right);
	cout << leaf->key_value << " ";
}

void printInorder(node *leaf)
{
	if (leaf == nullptr)
		return;
	printInorder(leaf->left);
	cout << leaf->key_value << " ";
	printInorder(leaf->right);
}

void printPreorder(node *leaf)
{
	if (leaf == nullptr)
		return;
	cout << leaf->key_value << " ";
	printPreorder(leaf->left);
	printPreorder(leaf->right);
}

