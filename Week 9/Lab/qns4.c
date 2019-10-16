// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists
// Template for Q2, Q3, and Q4

//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

//////////////////////////////////////////////////////

int searchList(ListNode *head, int value);

//////////////////////////////////////////////////////

int main()
{
	ListNode *head, *p, *temp;
	int n, i;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

 ////////////////////////////////////////////////////////////////////

	// Question 2
	//Write your program code here
	scanf("%d", &n);
	while (n != -1) {
		if (head == NULL) {
			head = malloc(sizeof(ListNode));
			if (head == NULL) {
				printf("Cannot allocate memory\n");
				return 1;
			}
			head->item = n;
			head->next = NULL;
			p = head;
		}
		else {
			p->next = malloc(sizeof(ListNode));
			if (p->next == NULL) {
				printf("Cannot allocate memory\n");
				return 1;
			}
			p = p->next;
			p->item = n;
			p->next = NULL;
		}

		scanf("%d", &n);
	}

	printf("Current list: ");
	temp = head;
	while (temp != NULL) {
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");

//////////////////////////////////////////////////////////////////////

//search for a value in the list. Q3

	printf("Enter value to search for:");
	scanf("%d", &n);
	i = searchList(head,n);
	printf("Value %d found at index %d", n, i);

/////////////////////////////////////////////////////////

    //free up memory for question 4
	//this part is wrong. It will cause problems.
/*	p = head;
	while (p!= NULL) {
		free(p);
		p=p->next;
	}
*/


	// Question 4
	//rewrite the free up using temporary pointer temp.
	temp = head;
	while (temp != NULL && p != head) {
		temp = head;
		if (p == head) {    // last = first == only 1 item in linked list
			free(p);
			break;
		}
		else {  // more than 1 item in the linked list
			while (temp->next != p) {
				temp = temp->next;
			}
			free(p);
			temp->next = NULL;
			p = temp;
		}
	}

/////////////////////////////////////////////////////////
	return 0;
}

////////////////////////////////////////////////////////////

int searchList(ListNode *head, int value)
{

////////////////////////////////////////////////////////////////////

	// Question 3
	//Write your program code here
	int i;

	i = 0;
	while (head != NULL) {
		if (head->item == value) {
			break;
		}
		i++;
		head = head->next;
	}
	if (head == NULL) {
		i = -1;
	}
	return i;

//////////////////////////////////////////////////////////////////////
}
