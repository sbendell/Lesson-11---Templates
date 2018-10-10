// Lesson 11 - Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
	Matrix<char> charMat(3, 3);

	for (int y = 0; y < charMat.get_y_size(); y++)
	{
		for (int x = 0; x < charMat.get_x_size(); x++)
		{
			charMat.set_element(x, y, char(97 + x + (y * 3)));
		}
	}

	for (int y = 0; y < charMat.get_y_size(); y++)
	{
		for (int x = 0; x < charMat.get_x_size(); x++)
		{
			cout << charMat.get_element(x, y);
		}
	}

	BinaryTree<int> treeInt(9);
	for (int i = 0; i < 20; i++)
	{
		treeInt.insert_integer(treeInt.get_primary_node(), i);
	}

	cout << "\n\n\nTree of integers: \n";
	treeInt.print_tree(treeInt.get_primary_node());

	BinaryTree<char> treeChar('j');
	for (int i = 0; i < 20; i++)
	{
		treeChar.insert_integer(treeChar.get_primary_node(), char(97 + i));
	}

	cout << "\n\n\nTree of characters: \n";
	treeChar.print_tree(treeChar.get_primary_node());

	int x;
	cin >> x;

    return 0;
}

