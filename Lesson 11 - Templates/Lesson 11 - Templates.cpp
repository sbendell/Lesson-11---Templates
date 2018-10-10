// Lesson 11 - Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"

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

	int x;
	cin >> x;

    return 0;
}

