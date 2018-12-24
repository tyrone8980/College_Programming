//============================================================================
// Name        : funWithLinkedLists2.cpp
// Author      : Oren
// Version     : 0.0.1
// Copyright   : None Enjoy
// Description : Basic linked list operations (OO)
//============================================================================

#include <iostream>
using namespace std;

typedef int ListDataType;
class List
{
private:
	// forward declaration of class node so we can create a node pointer typedef
	class Node;
	typedef Node *NodePtr;
	//
	// Linked list Node
	//
	class Node
	{
	public:
		Node(ListDataType data, NodePtr next)
	    {
		   	this->data = data;
		   	this->next = next;
	    }
		//typedef Node *Ptr;
		ListDataType data;
		//Node::Ptr next;
		NodePtr next;
	};

	// data
	unsigned int m_size;
	//Node::Ptr m_listHead;
	NodePtr m_listHead;


public:
	List(): m_size(0), m_listHead(0){}
	unsigned int size() { return m_size; }
	// public interface
	NodePtr insertItem(int value);
	void printListValues();
	bool findValueInList(int value);
	void deleteValueFromList(int value);
	void insertItemAtEndOfList(int value);
};

//
// traverse list and print data
//
void List::printListValues()
{
	Node* tempPtr = m_listHead;
	while (tempPtr != 0)
	{
		cout << tempPtr->data << endl;
		tempPtr = tempPtr->next;
	}
}

//
// search list for data item
//
bool List::findValueInList(int value)
{
	Node* tempPtr = m_listHead;
	while (tempPtr != 0)
	{

		if (tempPtr->data == value)
			// return value found!
			return true;

		tempPtr = tempPtr->next;
	}
	// return value not find
	return false;
}

//
// delete data item from list
//
void List::deleteValueFromList(int value)
{
	Node* tempPtr = m_listHead;
	Node* prevPtr = 0;
	while (tempPtr != 0)
	{
		if (tempPtr->data == value)
		{
			// if first item in the list
			if (prevPtr == 0)
			{
				// move the list head to the next item
				m_listHead = m_listHead->next;
			}
			else  // if not first item in the list
			{
				// connect previous item to next item
				prevPtr->next = tempPtr->next;
			}
			m_size--;// delete data item
			delete tempPtr;
			// break out of loop
			break;
		}
		// save predecessor
		prevPtr = tempPtr;
		// move to next item
		tempPtr = tempPtr->next;
	}
}

List::NodePtr List::insertItem(int value)
{
	m_size++;
	// create a new item that points to the head of the list
	m_listHead = new Node(value,m_listHead);
	return m_listHead;
}
//
// insert item at end of list
//
void List::insertItemAtEndOfList(int value){
m_size++;
Node* tempPtr = m_listHead;
Node* prevPtr = 0;
while(tempPtr != 0)
{

	prevPtr=tempPtr;
	tempPtr=tempPtr->next;
	}

tempPtr=new Node(value,m_listHead);
tempPtr->data=value;
prevPtr->next=tempPtr;
tempPtr->next =0;
	
	/**tempPtr-> data = value;
	tempPtr-> next = NULL;
	prevPtr-> data = value;
	prevPtr-> next= tempPtr;
	tempPtr-> next= newlast;
	newlast-> data = value;
	newlast-> next = NULL;
	**/

}

void runLinkedListTest1()
{
    cout<<"Class Code Test"<<endl;

	// first lets run some simple tests similar to what we did in class
	//Node *first = new Node;
	//Node *second = new Node;
	//Node *third = new Node;

	//first->data  = 1;
	//first->next = second;
	//second->data = 2;
	//second->next = third;
	//third->data  = 3;
	//third->next = 0;

    List myList;
    myList.insertItem(1);
    myList.insertItem(2);
    myList.insertItem(3);
    myList.insertItemAtEndOfList(4);

	// traverse list and print data
	//printListValues(first);
    myList.printListValues();
	// search list for data value
	if(myList.findValueInList(1))
	  cout<<"Value found!"<<endl;
	// delete data data value from list
	myList.deleteValueFromList(3);
	myList.deleteValueFromList(2);
	myList.deleteValueFromList(1);

    cout<<"Create Code Test"<<endl;
	// now lets generalize some more...
	// create a list of items
	const int ListSize = 10;
	//Node *listHead = createAListAndReturnListHead(ListSize);
    for(int i=0;i<ListSize;i++)
    	myList.insertItem(i);


myList.insertItemAtEndOfList(12);
	// traverse list and print data
	//printListValues(listHead);
	
    myList.printListValues();

	// search list for data values and display of found
    for(int i=0;i<ListSize;i++)
    {
	  //if(findValueInList(listHead,i))
  	  if(myList.findValueInList(i))
		cout<<"Value found: "<<i<<endl;
    }

    cout<<"Delete tests: phase 1"<<endl;

    // delete from the beginning of the list
    //deleteValueFromList(listHead,0);
    myList.deleteValueFromList(0);
    // delete from the middle of the list
    //deleteValueFromList(listHead,ListSize/2);
    myList.deleteValueFromList(ListSize/2);
    // delete from the end of the list
    //deleteValueFromList(listHead,ListSize-1);
    myList.deleteValueFromList(ListSize-1);

	// traverse list and print data
	//printListValues(listHead);
    myList.printListValues();

	cout<<"Delete tests: phase 2"<<endl;

    // delete all other values
    for(int i=0;i<ListSize;i++)
	  //deleteValueFromList(listHead,i);
      myList.deleteValueFromList(i);

	// traverse list and print data
	//printListValues(listHead);
    myList.printListValues();
	//if(listHead==0)
    if(myList.size()==0)
		cout<<"List is empty"<<endl;
	else{
		cout<<"The list is not empty the size is "<<myList.size()<<endl;
	}
}

int main()
{
	// run linked list tests
	runLinkedListTest1();

	return 0;
}
