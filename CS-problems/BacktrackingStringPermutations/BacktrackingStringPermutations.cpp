// BacktrackingStringPermutations.cpp
// Given a string of characters, use backtracking to output all
// possible permutations of the characters in the string.

//
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

void swap(char* s, int left, int right)
{
    char tmp = *(s + left);
    s[left] = s[right];
    s[right] = tmp;
}

void permute(char* s, int left, int right)
{
	if (left == right)
		cout << s << endl;
	else
	{
		for (int i = left; i < right; i++)
		{
			swap(s, left, i);
			permute(s, left+1, right);
			swap(s, i, left);
		}
	}
}

int main()
{
	char s[] = "ABCD";
	permute(s, 0, strlen(s));

    char s2[] = "EF.GH";
    permute(s2, 0, strlen(s2));

    string exit;
    cout << "Press enter to exit..." << endl;
    getline(cin, exit);

    return 0;
}

