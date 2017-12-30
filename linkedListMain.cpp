// Program:		Linked List
// Author:		Holly Eaton
// Description:	Linked list for tracking items in a list

#include "linkedList.h"

void controlMenu(LL someLL);
void useLinkedList(char optionPicked, LL someLL);

void main()
{
	LL* testList;
	testList = new LL;

	controlMenu(*testList);

	cin.get();
}

//=====================================================================
//Function Name: controlMenu
//
//Description: presents and validates for inserting, removing, deleting all
//				printing, printing in reverse and counting items with an ordered linked list
//
//Parameters: (I) someLL - the linked list being worked with
//=====================================================================
void controlMenu(LL someLL)
{
	string userSelection = "";

	cout<<"\nChoose an option: "<<endl;
	cout<<"A - Add an item"<<endl;
	cout<<"R - Remove an item"<<endl;
	cout<<"D - Delete all items from the list"<<endl;
	cout<<"C - Count the items in the list"<<endl;
	cout<<"P - Print the list"<<endl;
	cout<<"V - Print the list in reverse order"<<endl;
	cout<<endl;
	cout<<">";
	getline(cin, userSelection);

	while (toupper(userSelection[0]) != 'C' &&
		toupper(userSelection[0]) != 'D' &&
		toupper(userSelection[0]) != 'A' &&
		toupper(userSelection[0]) != 'P' &&
		toupper(userSelection[0]) != 'R' &&
		toupper(userSelection[0]) != 'V')
	{
		cout << "Select Option: ";
		getline(cin, userSelection);
	}

	useLinkedList(toupper(userSelection[0]), someLL);
}

//=====================================================================
//Function Name: useLinkedList
//
//Description: applies user selected operation on an ordered linked list,
//				displays if action was successful or not,
//				displays updated list
//
//Parameters: (I) optionPicked - the char determining the action to perform
//				(I/O) someLL - the linked list being interacted with
//=====================================================================
void useLinkedList(char optionPicked, LL someLL)
{
	string someName;
	char confirmDeleteList = '\0';

	switch (optionPicked)
	{
	case 'C':
		cout<<"   ";
		someLL.count();
		cout<<" Items are in the list."<<endl;
		break;
	case 'D':
		cout<<"Are you sure you want to delete the entire list? (y/n)";
		cout<< ">";
		cin>>confirmDeleteList;

		while(!(tolower(confirmDeleteList) == 'y' || tolower(confirmDeleteList) == 'n'))
		{
			cout<<"Enter y or n to comfirm that you want to delete the entire list."<<endl;
			cout<<">";
			cin>>confirmDeleteList;
		}
		if(tolower(confirmDeleteList) == 'y')
		{
			someLL.removeAll();
			cout <<"\nAll items have been removed\n";
			cout<<endl;
		}
		else
		{
			cout<<"\nNothing was removed from the list. "<<endl;
		}
		someLL.print();
		cout<<endl;
		break;
	case 'A':
		cout << "\nType the name to be inserted: ";
		getline(cin, someName);
		if (someLL.insert(someName))
			cout<< "\nName successfully added\n";
		else
			cout<< "\nNo name was added\n";
		someLL.print();
		cout<<endl;
		break;
	case 'P':
		someLL.print();
		cout<<endl;
		break;
	case 'R':
		cout<< "\nType the name to be removed: ";
		getline(cin, someName);
		if (someLL.remove(someName))
			cout<< "\nName successfully removed\n";
		else
			cout<< "\nNo name was removed\n";
		someLL.print();
		cout<<endl;
		break;
	case 'V':
		someLL.printReverse();
		cout<<endl;
		break;
	default:
		controlMenu(someLL);
	}

	controlMenu(someLL);
}