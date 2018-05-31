/* This is my library
Tyrone Harmon 
Operating Systems csc 112
Professor Thomas Re
*/
#include "mylib.h"
struct node* first = NULL; //will help with adding at front
void Insert_At_End(struct node* inserter)
{
	struct node *ptr = first;
	while(ptr!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = inserter;
	inserter->next = NULL;
}//end of insert at end

struct node* Delete_Node(int location)
{
	struct node* current = first;
	struct node* tail = NULL;
	if(first==NULL)
	{
		return NULL;
	} 
	while(current->location != location)
	{
		if(current->next==NULL)
		{
			return NULL;
		} else{
			tail = current; 
			current = current->next;
		}//end of else statement
	}//end of while loop
	if(current==first)
	{
		first = first->next;
	}else{
		tail->next = current-> next;
	}
	return current;
}//end of delete node

void Insert_In_Front(int location,int data)
{
	struct node *linker = (struct node*) malloc(sizeof(struct node));
	linker->location=location;
	linker->data= data;
	linker->next = first;
	first = linker;
}//end of insert in front 

struct node* Find(int location)
{
	struct node* current = first;
	if(first==NULL){return NULL;}
	while(current->location != location)
	{
		if(current->next ==NULL)
		{
			return NULL;	
		} else{
			current = current->next;
		}//end of else statement
	}//end of while loop 
	return current; //if the data has been discovered return the current node 

}//end of find function 
void Print_Node(int location)
{
	struct node *found = Find(location);
	printf("(%d,%d) ",found->location,found->data);

}//end of print node function

//print out the linked list 
void Print_List()
{
	struct node *ptr = first;
	printf("\n{ ");
	while(ptr != NULL)
	{
		printf("(%d,%d) ",ptr->location,ptr->data);
		ptr = ptr->next;
	}//end of while loop
}//end of print list
//useful function to see if list is already empty

bool isEmpty() {
   return first == NULL;
}//end of isEmpty

void Delete_List()
{
	struct node* tracker = first.next;
	//First check to see if list is already empty 
	if(isEmpty()== true ) {return;}
	while(tracker != NULL)
	{
		Delete_Node(first);
		free(first);
		tracker = tracker->next;
		first = first->next;
	}//end of while loop

}//end of delete list 
