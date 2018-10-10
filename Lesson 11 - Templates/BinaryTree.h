#pragma once
#include <iostream>

struct node {
	Comparable* value;
	struct node* left;
	struct node* right;
};

class BinaryTree
{
public:
	BinaryTree(Comparable* comparable);
	~BinaryTree();
	node* get_primary_node();
	void insert_integer(struct node* tree, Comparable* value);
	void print_tree(struct node* tree);
	void terminate_tree(struct node* tree);
	bool Search(struct node* leaf, Comparable* value) const;
private:
	node* primaryNode;
};

BinaryTree::BinaryTree(Comparable* comparable)
{
	primaryNode = new node();
	primaryNode->value = comparable;
	primaryNode->left = NULL;
	primaryNode->right = NULL;
}

node* BinaryTree::get_primary_node() {
	return primaryNode;
}

void BinaryTree::insert_integer(struct node* leaf, Comparable* value) {
	switch (value->compare_to(*leaf->value)) {
	case -1:
		if (leaf->left == NULL) {
			leaf->left = new node();
			leaf->left->value = value;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
		else {
			insert_integer(leaf->left, value);
		}
		break;
	case 0:
		if (leaf->right == NULL) {
			leaf->right = new node();
			leaf->right->value = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
		else {
			insert_integer(leaf->right, value);
		}
		break;
	case 1:
		if (leaf->right == NULL) {
			leaf->right = new node();
			leaf->right->value = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
		else {
			insert_integer(leaf->right, value);
		}
		break;
	}
}

void BinaryTree::print_tree(struct node* leaf) {
	if (leaf->left != NULL)
		print_tree(leaf->left);

	leaf->value->Print();

	if (leaf->right != NULL)
		print_tree(leaf->right);
}

void BinaryTree::terminate_tree(struct node* leaf) {
	if (leaf != NULL) {
		terminate_tree(leaf->left);
		terminate_tree(leaf->right);
		delete leaf;
		cout << "Deleted node at " << leaf << "\n";
	}
}

bool BinaryTree::Search(struct node* leaf, Comparable* value) const {
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

BinaryTree::~BinaryTree()
{
	terminate_tree(primaryNode);
}