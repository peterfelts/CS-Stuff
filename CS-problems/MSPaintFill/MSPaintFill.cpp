// MSPaintFill.cpp
//
// This project shows how to implement an iterative approach to flood
// filling part of a bitmap. Instead of recursion we use iteration and
// a queue. Given a bitmap (a 2D array of integers), a point (row and column 
// values in to the array), a target and a new color, fill all parts of the
// bitmap that are in contact with the specified point/pixel.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class Fill
{
public: 

    // Given an 2D vector of ints, a location (row/col), a target color and a new color
    // replace all "pixels" (ints) that match the target color. Use iteration and a queue
    // instead of recursion.
    void fillImage(vector<vector<int>> &bitmap, int rowTarget, int colTarget, int targetColor, int newColor)
    {

        // bail out of we're given a bitmap with invalid dimensions
        if (bitmap.size() == 0 || bitmap[0].size() == 0)
            return;

        // no need to do any work if the target and new color match
        if (targetColor == newColor)
            return;

        queue<pair<int, int>> q;

        // add the target pixel to the queue, if it is on the board
        if (isInBounds(bitmap, rowTarget, colTarget))
        {
            if (bitmap[rowTarget][colTarget] == targetColor)
                q.push(make_pair(rowTarget, colTarget));
        }
        else
            return;

        while (!q.empty())
        {
            // Pop the next item off the queue, and then add 
            // any appropriate neighboring pixels that match
            // the target color and are within the bounds of the
            // bitmap
            auto pixel = q.front();
            q.pop();
            int row = pixel.first;
            int col = pixel.second;

            if (bitmap[row][col] == targetColor)
            {
                bitmap[row][col] = newColor; // set the pixel value

                                             // add the top pixel (previous row)
                if (isInBounds(bitmap, row - 1, col))
                    q.push(make_pair(row - 1, col));

                // add the lower pixel (next row)
                if (isInBounds(bitmap, row + 1, col))
                    q.push(make_pair(row + 1, col));

                // add the left pixel (previous column)
                if (isInBounds(bitmap, row, col - 1))
                    q.push(make_pair(row, col - 1));

                // add the right pixel (next column)
                if (isInBounds(bitmap, row, col + 1))
                    q.push(make_pair(row, col + 1));
            }
        }
    }

	// print image to stdout
	void printImage(vector<vector<int>> &bitmap)
	{
		for (int row = 0; row < bitmap.size(); row++)
		{
			for (int col = 0; col < bitmap[0].size(); col++)
			{
				if (bitmap[row][col] == 0)
					cout << " ";
				else
					cout << bitmap[row][col];
			}
			cout << endl;
		}
	}

	// Helper function that returns true if the provided
	// row and column are within the bounds of the bitmap image
	bool isInBounds(vector<vector<int>> bitmap, int row, int col)
	{
		if ((row >= 0 && row < bitmap.size()) && (col >= 0 && col < bitmap[0].size()))
			return true;
		return false;
	}

	static void test(vector<vector<int>> &bitmap, int row, int col, int targetColor, int newColor)
	{
		Fill *fill = new Fill();
		cout << "Before fill:" << endl;
		fill->printImage(bitmap);
		fill->fillImage(bitmap, row, col, 1, newColor);
		cout << "After trying to fill pixel (" << row << "," << col << ") with target color (" << newColor << "):" << endl;
		fill->printImage(bitmap);
		free(fill);
	}
};

int main()
{
	vector<vector<int>> image0 = {
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1 },
		{ 0,0,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1 },
		{ 0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1 },
		{ 0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0 },
		{ 0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	};

	Fill::test(image0, 5, 5, 1, 5); // Fill giving a valid pixel coordinate
	Fill::test(image0, 0, 0, 5, 3); // Pass in an invalid (not matching) pixel coordinate

	string exit;
	cout << "Press enter to exit..." << endl;
	getline(cin, exit);

    return 0;
}

