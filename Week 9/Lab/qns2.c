// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists
// Template for Q2

//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;


int main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

	/////////////////////////////////////////////////////////////////

	//Question 2
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
    while (temp->next != NULL) {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("%d ", p->item);
    printf("\n");

   //////////////////////////////////////////////////////////////////

   return 0;
}
