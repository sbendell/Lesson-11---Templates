#pragma once
#include <iostream>

template <typename T>
class node {
public:
	T value;
	node<T>* left;
	node<T>* right;
};

template <typename T>
class BinaryTree
{
public:
	BinaryTree<T>(T object);
	~BinaryTree();
	node<T>* get_primary_node();
	void insert_integer(node<T>* tree, T object);
	void print_tree(node<T>* tree);
	void terminate_tree(node<T>* tree);
	bool Search(node<T>* leaf, T value) const;
private:
	node<T>* primaryNode;
};

template <typename T>
BinaryTree<T>::BinaryTree(T value)
{
	primaryNode = new node<T>();
	primaryNode->value = value;
	primaryNode->left = NULL;
	primaryNode->right = NULL;
}

template <typename T>
node<T>* BinaryTree<T>::get_primary_node() {
	return primaryNode;
}

template <typename T>
void BinaryTree<T>::insert_integer(node<T>* leaf, T value) {
	if (value < leaf->value) {
		if (leaf->left == NULL) {
			leaf->left = new node<T>();
			leaf->left->value = value;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
		else {
			insert_integer(leaf->left, value);
		}
	}
	else {
		if (leaf->right == NULL) {
			leaf->right = new node<T>();
			leaf->right->value = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
		else {
			insert_integer(leaf->right, value);
		}
	}
}

template <typename T>
void BinaryTree<T>::print_tree(node<T>* leaf) {
	if (leaf->left != NULL)
		print_tree(leaf->left);

	cout << leaf->value << "\n";

	if (leaf->right != NULL)
		print_tree(leaf->right);
}

template <typename T>
void BinaryTree<T>::terminate_tree(node<T>* leaf) {
	if (leaf != NULL) {
		terminate_tree(leaf->left);
		terminate_tree(leaf->right);
		delete leaf;
		cout << "Deleted node at " << leaf << "\n";
	}
}

template <typename T>
bool BinaryTree<T>::Search(node<T>* leaf, T value) const {
	if (leaf != NULL) {
		if (value == leaf->value) {
			return true;
		}
		else if (value < leaf->value) {
			if (leaf->left == NULL) {
				return false;
			}
			else {
				return Search(leaf->left, value);
			}
		}
		else if (value > leaf->value) {
			if (leaf->right == NULL) {
				return false;
			}
			else {
				return Search(leaf->right, value);
			}
		}
	}
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	terminate_tree(primaryNode);
}