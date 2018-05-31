/*
Tyrone Harmon 
Operating Systems csc 112
Professor Thomas Re
*/
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
//My prototypes 
struct node{
	int data;
	int location;//this way we can see where it is at in the linked list
	struct node* next;
};
void Insert_At_End(struct node* inserter);
struct node* Delete_Node(int location);
void Insert_In_Front(int location,int data);
struct node* Find(int location);
void Print_Node(int location);
void Print_List();
bool isEmpty()
void Delete_List();
