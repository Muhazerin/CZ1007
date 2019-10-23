// CE1007/CZ1007 Data Structures
// Week 10 Lab Tutorial - Linked List

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////
////////////

typedef struct _listnode{
	int num;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	ListNode *head;
	int size;
} LinkedList;

////////////////////////////////////////////////////////////////////////////////

int removeNode(ListNode **ptrHead, int index);
int removeNode2(LinkedList *ll, int index);
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode *head, ListNode **ptrNewHead);

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);

////////////////////////////////////////////////////////////////////////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	LinkedList llist;
	int size = 0;

	//build a linked list
	if (insertNode(&head, 0, 6) == 0) size++;
	if (insertNode(&head, 0, 4) == 0) size++;
	if (insertNode(&head, 0, 2) == 0) size++;
	printf("After inserting 3 values.");
	printList(head);


	//removeNode(): question 1
	if (removeNode(&head, 3) == 0) size--;//this one can't be removed.
	if (removeNode(&head, 1) == 0) size--;
	if (removeNode(&head, 0) == 0) size--;

	printf("\nafter remove using removeNode(), ");
	printList(head);

    //insert some nodes
	if (insertNode(&head, 2, 3) == 0) size++; // this one can't be inserted.
	if (insertNode(&head, 1, 1) == 0) size++;
	if (insertNode(&head, 0, 0) == 0) size++;

	printf("\nafter insert, ");
	printList(head);

	//removeNode2(): question 2
	llist.head = head;
	llist.size = size;
	removeNode2(&llist, 2);
	removeNode2(&llist, 0);
	removeNode2(&llist, 0);
	head = llist.head;


	printf("\nafter remove using removeNode2(), ");
	printList(llist.head);
	// empty linked list now

    //split(): question 3
	for (i = 1; i <10; i++)//build a new linked list
		insertNode(&head, 0, i);
	printf("\n\ninsert 1-9 to the linked list,");
	printList(head);
	printf("split the current list, results:\n");
	split(head, &evenHead, &oddHead);
	printf("the even list\n");
	printList(evenHead);
	printf("the odd list\n");
	printList(oddHead);

    //duplicateReverse(): question 4
	printf("\n");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);

    return 0;
}
////////////////////////////////////////////////////////////////////////////////

void printList(ListNode *head){
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL){
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}

int insertNode(ListNode **ptrHead, int index, int value){
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////

int removeNode(ListNode **ptrHead, int index) 
{
	// write your code here
    ListNode *pre, *cur = *ptrHead;
    if (*ptrHead != NULL) {
        if (index == 0) {   // remove first item
            *ptrHead = cur->next;
            free(cur);
            return 0;
        }
        else {  // remove N-th item
            /*while (cur != NULL) {	// this algorithm also works
                if (index == 0) {
                    pre->next = cur->next;
                    free(cur);
                    return 0;
                }
                index--;
                pre = cur;
                cur = cur->next;
            }*/
	    // tutor's algorithm
	    // find the node before and after the target position
	    // free the target node and reconnect the links
	    if ( (pre = findNode(*ptrHead, index - 1)) != NULL) {
		    if (pre->next == NULL) {
			    return -1;
		    }
		    cur = pre->next;
		    pre->next = cur->next;
		    free(cur);
		    return 0;
	    }
        }
    }
    return -1;
}

////////////////////////////////////////////////////////////////////////////////

int removeNode2(LinkedList *ll, int index) 
{
	// write your code here
    ListNode *pre, *cur = ll->head;

    if (cur != NULL) {  // not empty list
        if (index == 0) {   // remove first item
            ll->head = cur->next;
            free(cur);
            (ll->size)--;
            return 0;
        }
        else {  // remove N-th item
            /*while (cur != NULL) {
                if (index == 0) {
                    pre->next = cur->next;
                    free(cur);
                    (ll->size)--;
                    return 0;
                }
                index--;
                pre = cur;
                cur = cur->next;
            }*/
	    if ((pre = findNode(ll->head, index-1)) != NULL) {
		    if (pre->next == NULL) {
			    return -1;	
		    }
		    cur = pre->next;
		    pre->next = cur->next;
		    free(cur);
		    (ll->size)--;
		     return 0;
	    }
        }
    }
    return -1;
}

////////////////////////////////////////////////////////////////////////////////

int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList)
{
	// write your code here
    int evenIndex, oddIndex, index;

    evenIndex = oddIndex = index = 0;
    while (head != NULL) {
        if ((index % 2) == 0) {
            insertNode(ptrEvenList, evenIndex++, head->num);
        }
        else {
            insertNode(ptrOddList, oddIndex++, head->num);
        }
        index++;
        head = head->next;
	return 0;
    }
    return -1;
}

////////////////////////////////////////////////////////////////////////////////

int duplicateReverse(ListNode *head, ListNode **ptrNewHead)
{
	// write your code here
	if (head != NULL) {	// if list is not empty
		while (head != NULL) {
			insertNode(ptrNewHead, 0, head->num);
			head = head->next;
		}
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////
