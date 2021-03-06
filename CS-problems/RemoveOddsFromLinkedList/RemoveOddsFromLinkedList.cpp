// RemoeOddsFromLinkedList.cpp : 
// This file shows how walk through a linked list and remove
// nodes, in the case of this example we're removing nodes that
// contain odd values.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
	int val;
	Node* next;
};

class RemoveOddFromLinkedList
{
public:

	// Walk through a linked list and remove nodes that contain
	// odd int values
	void removeOdd(Node** head)
	{
		Node* tmp = *head;
		Node* prev = nullptr;
		while (tmp != nullptr)
		{
			// remove nodes that contain odd values
			if (tmp->val % 2 != 0)
			{
				// special case if the first node is odd
				if (tmp == *head)
				{
					*head = tmp->next; // point the head to the next node
					free(tmp); // free up the deleted node's memory
					tmp = *head;

				// otherwise, point the previous node to the 
				// next node.
				}else {
					prev->next = tmp->next;
					free(tmp); // free up the deleted node's memory
					tmp = prev->next;
				}
			}
			else {
				// store the current node as the previous node,
				// and get the next node
				prev = tmp;
				tmp = tmp->next;
			}
		}
	}

	// Given an int array, a length, and a pointer to a Node, build
	// the linked list with the values in the array
	void CreateLinkedList(int nums[], int length, Node** head)
	{
		if (length > 0)
		{
			Node *prev = nullptr;
			for (int i = 0; i < length; i++)
			{

				Node* newNode = new Node;
				newNode->val = nums[i];
				newNode->next = nullptr;

				// point the previous node at the new node
				if (prev != nullptr)
					prev->next = newNode;

				// the first time through, set the new node as the head
				else
					*head = newNode;

				// keep track of the current node, so that we can
				// point it to the next node we create
				prev = newNode;

			}
		}
	}

	// Output the linked list to std out
	void PrintLinkedList(Node** head)
	{
		Node* tmp = *head;
		while (tmp != nullptr)
		{
			cout << tmp->val << " -> ";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}

	// Test method. Given an int array and a length:
	// 1) Build a linked list from the int array
	// 2) Print the created linked list
	// 3) Remove odd values from the list
	// 4) Print the updated linked list
	// 5) free up memory
	// 
	// Node: manual observation required to validate the tests
	void test(int nums[], int length)
	{
		Node* testLinkedList = nullptr;
		this->CreateLinkedList(nums, length, &testLinkedList);
		cout << "Input: ";
		this->PrintLinkedList(&testLinkedList);
		this->removeOdd(&testLinkedList);
		cout << "Output: ";
		this->PrintLinkedList(&testLinkedList);
		cout << endl;
		
		// Free up the list
		Node* tmp = testLinkedList;
		Node* tmp2 = nullptr;
		while (tmp != nullptr)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}

	}
};


int main()
{

	RemoveOddFromLinkedList *remove = new RemoveOddFromLinkedList;

	// simple test
	int test[] = { 1,2,3,4,5,6 };
	remove->test(test, size(test));

	// testing with mixed negative and positive values
	int test2[] = { 0,-1,4,1018,-32,4,12,0,0,0,1,2,3,4 };
	remove->test(test2, size(test2));

	// testing a single odd number in a chain of even numbers
	int test3[] = { -2,-2,-2,-2,-1,2,2,2,2,2,2 };
	remove->test(test3, size(test3));

	// testing null input
	remove->test(nullptr, 0);

	// testing all odds
	int test5[] = { -1,-1,-1,-1,1,1,1,1,1 };
	remove->test(test5, size(test5));

	// all odds, except for the final item in the test array
	int test6[] = { -3,3,-3,3,-3,3,-3,3,-3,2 };
	remove->test(test6, size(test6));

	// testing a single odd node
	int test7[] = { 1 };
	remove->test(test7, size(test7));

	// testing a list that starts odd and ends even
	int test8[] = { 1,2 };
	remove->test(test8, size(test8));

	// test a single even number
	int test9[] = { 2 };
	remove->test(test9, size(test9));

	string exit;
	cout << "Press enter to exit..." << endl;
	getline(cin, exit);

    return 0;
}

