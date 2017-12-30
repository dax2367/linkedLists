// Program:		Linked List
// Author:		Holly Eaton
// Description:	Linked list for tracking items in a list

#include <string>
#include <iostream>
#include <cctype>


using namespace std;

#ifndef LL_H
#define LL_H

class LL
{
private:
	struct Node
	{
		string name;
		Node* next;	
	};

	Node* head;
	void removeNode(Node* n);
	void displayNode(Node* n);
	void nodeCount(Node* n);
	void printNodeReverse(Node* n);

public:
	LL::LL();
	~LL();
	bool insert(string name);
	bool remove(string name);
	void removeAll();
	void print();
	void count();
	void printReverse();
};

#endif
