// Program:		Linked List
// Author:		Holly Eaton
// Description:	Linked list for tracking items in a list

#include "linkedList.h"

/*===============================================================================================
Function name:	LL
Description:	Constructor, sets head to NULL
Arguments:		None
Return value:	None
===============================================================================================*/
LL::LL()
{
	head = NULL;
}

/*===============================================================================================
Function name:	~LL
Description:	Destructor, calls removeAll()
Arguments:		None
Return value:	None
===============================================================================================*/
LL::~LL()
{
	removeAll();
}

/*===============================================================================================
Function name:	insert
Description:	Inserts a unique item alphabetically into the list
Arguments:		(I) name - The data that will be inserted into the list
Return value:	bool - True if the item was inserted, False item already exists
===============================================================================================*/
bool LL::insert(std::string name)
{
	//create and initialize node
	Node* newNode = new Node;
	newNode->name = name;
	newNode->next = NULL;

	if (head == NULL)
	{
		//List is empty go ahead and insert data
		head = newNode;
		return true;
	}	
	else if (newNode->name < head->name)
	{
		//data to insert is first alphbetically so it becomes the first item
		newNode->next = head;  //point at the current head first
		head = newNode;  //then point head at the new item second
		return true;
	}	
	else if (newNode->name == head->name) //is it a duplicate?
	{	
		return false;
	}
	else  //Ok then it must go in the middle or at the end
	{
		//find where it goes
		Node* prev = head;
		while (prev->next != NULL && prev->next->name < newNode->name)
		{
			prev = prev->next;
		}

		//is it a duplicate?
		if (prev->next != NULL && prev->next->name == newNode->name)
		{
			return false;
		}
		else //Ok then insert the item
		{
			newNode->next = prev->next;
			prev->next = newNode;
			return true;
		}
	}
}

/*===============================================================================================
Function name:	remove
Description:	Remove the specified item from the list
Arguments:		 (I) name - The data that will be removed from the list
Return value:	bool - True if the item was removed, False if head is NULL or item doesn't exist
==================================================================================================*/
bool LL::remove(string name)
{
	//is list empty?
	if(head == NULL)
		return false;

	if(name == head->name) //delete first item
	{
		Node* nodeToDelete = head;
		head = head->next;
		delete nodeToDelete;
		return true;
	}

	//find node in middle to delete
	Node* current = head->next;
	Node* prev = head;

	while(current !=NULL && current->name < name)
	{
		prev = current;
		current = current ->next;
	}
	if(current !=NULL && current->name == name)
	{
		prev->next = current->next;
		delete current;
		return true;
	}

	//item wasn't found
	return false;
}

/*===============================================================================================
Function name:	removeAll
Description:	Removes all items in the list
Arguments:		None
Return value:	None
===============================================================================================*/
void LL::removeAll()
{
	//if head isn't NULL remove all items from the list
	if (head !=NULL)
	{
		removeNode(head);
	}
	head = NULL;
}

/*===============================================================================================
Function name:	removeNode
Description:	Removes all nodes from the list
Arguments:		(I)n - the node to be removed
Return value:	None
===============================================================================================*/
void LL::removeNode(Node* n)
{
	if(n->next != NULL)
	{
		removeNode(n->next);
		delete n;
	}
}

/*===============================================================================================
Function name:	print
Description:	Print out the items in the list
Arguments:		None
Return value:	None
===============================================================================================*/
void LL::print()
{
	if (head != NULL)
		displayNode(head);
	else
		cout << "No items in list. Please choose another menu item.\n";
}

/*===============================================================================================
Function name:	displayNode
Description:	Displays the data of one node in the console window
Arguments:		(I) n - the node whose data is to be displayed
Return value:	None
===============================================================================================*/
void LL::displayNode(Node* n)
{
	if(n->next !=NULL)
	{
		cout<<n->name<<", ";
		displayNode(n->next);	
	}
	if(n->next == NULL)
		cout<<n->name;
}

/*====================================================================================================
Function name:	count
Description:	Determines the number of items in the list and displays total in the console window
Arguments:		None
Return value:	None
=====================================================================================================*/
void LL::count()
{
	if (head != NULL)
		nodeCount(head);
	else
		cout << "There are no items in the list\n";
}

/*====================================================================================================
Function name:	nodeCount
Description:	Determines if a node exists to be counted
Arguments:		(I) n - the node to be examined
Return value:	None
=====================================================================================================*/
void LL::nodeCount(Node* n)
{
	static int total = 0;
	if(head == NULL)
		return;

	if(n->next != NULL)
	{
		total++;
		nodeCount(n->next);
	}
	if(n->next == NULL)
	{
		total++;
		cout<<total;
		total = 0;
	}
}

/*====================================================================================================
Function name:	printReverse
Description:	Displays the contents of list in reverse order
Arguments:		None
Return value:	None
=====================================================================================================*/
void LL::printReverse()
{
	printNodeReverse(head);
	cout<<"\n";
}

/*====================================================================================================
Function name:	printNodeReverse
Description:	Displays the data of a node
Arguments:		(I) n - the node being examined
Return value:	None
=====================================================================================================*/
void LL::printNodeReverse(Node* n)
{
	if(n->next != NULL)
		printNodeReverse(n->next);
	if(n != head)
		cout<<n->name<< ", ";
	else
		cout<<n->name;
}
