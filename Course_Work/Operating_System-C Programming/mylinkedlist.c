/*
Tyrone K Harmon Jr. 
Operating System CSC 112
Professor Thomas Re

Create a Linked list in C.  This program will contain functions that use pointers and dynamic memory allocation. You will be using a struct for the node.  The node will only have an int for the data and a pointer called next;

Functions include

1)Insert_At_End COMPLETED 

2)Delete_Node COMPLETED

3)Insert_In_Front COMPLETED

4)Find(int data) COMPLETED

5)print_node COMPLETED

7)print_list COMPLETED 

8)delete_list

The UI for interacting with the user is up to the student.


*/
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"


//now create some variables to help smoothin out the process later
//First is going to be my century node that will moniter the front 
struct node* first = NULL; //will help with adding at front
struct node* last= NULL; //will help with adding at the end 
struct node*current = NULL;



int main()
{
	/* Do some stuff to test the list*/	
}



