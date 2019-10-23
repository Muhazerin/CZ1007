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
typedef struct _dbllistnode{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

////////////////////////////////////////////////////////////////////
////////////
int removeNode(ListNode **ptrHead, int index);
int removeNode2(LinkedList *ll, int index);
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode *head, ListNode **ptrNewHead);

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);


// these are for the practice questions
int moveMaxToFront(ListNode **ptrHead);
int concatenate(ListNode **ptrHead1, ListNode *head2);
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);
int insertDbl(DblListNode **ptrHead, int index, int value);
void printDblList(DblListNode *head);

////////////////////////////////////////////////////////////////////
////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	DblListNode *dblHead = NULL;
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
	printf("the even list");
	printList(evenHead);
	printf("the odd list");
	printList(oddHead);

	//duplicateReverse(): question 4
	printf("\n");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);

	////////////////////////////////////////////////////////////////////////
	//the following are for the PRACTICE QUESTIONS

	printf("\n\nNow for the practice questions");

	//1.moveMaxToFront()
	printf("\n************** moveMaxToFront *******************\n");
	printList(dupRevHead);
	moveMaxToFront(&dupRevHead);
	printf("after moveMaxToFront()");
	printList(dupRevHead);

	//2. concatenate()
	printf("\n************** concatenate() *******************\n");
	concatenate(&head, dupRevHead);
	printf("concatenate(current list, duplicate reverse list)\n  ");
	printList(head);

	//3.combineAlternating()
	printf("\n************** combineAlternating() *******************\n");
	for (i = 3; i > 0; i--)				//build linked list 1
		insertNode(&list1Head, 0, i);
	for (i = 13; i > 10; i--)			//build linked list 2
		insertNode(&list2Head, 0, i);
	printf("List 1:");
	printList(list1Head);
	printf("List 2: ");
	printList(list2Head);
	combineAlternating(&combAltHead, list1Head, list2Head);
	printf("After combineAlternating(): ");
	printList(combAltHead);

	//4. insertDbl()
	printf("\n************** insertDbl() *******************\n");
	printf("insertDbl()\nDoubly-linked list: ");
	insertDbl(&dblHead, 0, 10);
	insertDbl(&dblHead, 0, 20);
	insertDbl(&dblHead, 1, 30);
	insertDbl(&dblHead, 2, 40);
	printDblList(dblHead);
	return 0;
}

////////////////////////////////////////////////////////////////////
////////////

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

void printDblList(DblListNode *head){
	if (head == NULL) return;
	while (head != NULL){
		printf("%d ", head->num);
		head = head->next;
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
            while (cur != NULL) {
                if (index == 0) {
                    pre->next = cur->next;
                    free(cur);
                    return 0;
                }
                index--;
                pre = cur;
                cur = cur->next;
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
            while (cur != NULL) {
                if (index == 0) {
                    pre->next = cur->next;
                    free(cur);
                    (ll->size)--;
                    return 0;
                }
                index--;
                pre = cur;
                cur = cur->next;
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
    }
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

int moveMaxToFront(ListNode **ptrHead)
{
	// write your code here
	int item, index, curIndex;
	ListNode *cur;

    if (*ptrHead != NULL) { // if list is not empty
        cur = *ptrHead;
        item = cur->num;
        curIndex = index = 0;

        cur = cur->next;    // traverse the list
        curIndex++;
        while (cur != NULL) {
            if (cur->num > item) {
                item = cur->num;
                index = curIndex;
            }
            curIndex++;
            cur = cur->next;
        }

        removeNode(ptrHead, index);
        insertNode(ptrHead, 0, item);
        return index;
    }
    return -1;
}


int concatenate(ListNode **ptrHead1, ListNode *head2)
{
	// write your code here
	ListNode *temp;

    if (*ptrHead1 != NULL || head2 != NULL) {   // if both lists are not empty
        if (*ptrHead1 == NULL) {    // if ptrHead1 is empty
            *ptrHead1 = head2;
            return 0;
        }
        else if (head2 == NULL) {    // if head2 is empty, do nothing
            return 0;
        }
        else {  // if both list have items
            temp = *ptrHead1;
            while (temp->next != NULL) {  // traverse the first list
                temp = temp->next;
            }
            temp->next = head2;
            return 0;
        }
    }
    return -1;
}


int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2)
{
	// write your code here
	int curIndex = 0;

    if (head1 != NULL || head2 != NULL) {   // if both lists are not empty
        while (head1 != NULL && head2 != NULL) {
            if (head1 != NULL) {    // if current head1 is not NULL,  add and traverse to the next node
                insertNode(ptrHead, curIndex++, head1->num);
                head1 = head1->next;
            }
            if (head2 != NULL) {    // if current head2 is not NULL, add and traverse to the next node
                insertNode(ptrHead, curIndex++, head2->num);
                head2 = head2->next;
            }
        }
        return 0;
    }
    return -1;
}


int insertDbl(DblListNode **ptrHead, int index, int value)
{
	// write your code here
	DblListNode *pre, *cur, *temp;

    if (*ptrHead == NULL) { // if list is empty,
        if (index == 0) {   // index given should be 0
            *ptrHead = malloc(sizeof(DblListNode));
            (*ptrHead)->num = value;
            (*ptrHead)->next = NULL;
            (*ptrHead)->pre = NULL;
            return 0;
        }
        else {
            return -1;
        }
    }
    else {  // list is not empty
        if (index == 0) {   // add at the front
            cur = *ptrHead;
            *ptrHead = malloc(sizeof(DblListNode));
            (*ptrHead)->num = value;
            (*ptrHead)->next = cur;
            (*ptrHead)->pre = NULL;
            cur->pre = *ptrHead;
            return 0;
        }
        else {  // add at N-th index
            cur = *ptrHead;
            while (cur != NULL) {
                if (index == 0) {
                    temp = malloc(sizeof(DblListNode));
                    temp->num = value;
                    temp->pre = pre;
                    pre->next = temp;
                    temp->next = cur;
                    cur->pre = temp;
                    return 0;
                }
                index--;
                pre = cur;
                cur = cur->next;
            }
            if (cur == NULL && index == 0) {    // add at the last
                temp = malloc(sizeof(DblListNode));
                temp->num = value;
                temp->next = NULL;
                temp->pre = cur;
                cur->next = temp;
                return 0;
            }
            else {
                return -1;
            }
        }
    }
}


////////////////////////////////////////////////////////////////////
