//////////////////////////////////////////////////////////////////////

// CE1007/CZ1007 Data Structures
// Week 13 Lab and Tutorial - Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);
	printf("\n");

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	// write your code here
	BTNode *temp;

    if (*node == NULL) {    // the tree is empty OR new node
        temp = malloc(sizeof(BTNode));
        temp->left = NULL;
        temp->right = NULL;
        temp->item = value;
        *node = temp;
        return;
    }
    else {  // if there is at least a single item in the tree
        if (value < (*node)->item) {    // if smaller, traverse to left
            insertBSTNode(&(*node)->left, value);
        }
        else if (value > (*node)->item) {   // if bigger, traverse to right
            insertBSTNode(&(*node)->right, value);
        }
        else {  // same value
            printf("Cannot insert. Item already exist in tree\n");
        }
    }
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	// write your code here
	if (node == NULL) { // if tree is empty or current node is NULL
        return;
	}
	printBSTInOrder(node->left);    // traverse left
	printf("%d ", node->item);      // print current node value
	printBSTInOrder(node->right);   // traverse right
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	// write your code here
	/*if (node == NULL) {     // if the tree is empty
        return 0;
	}
	else {
	    if (node->item > max || node->item < min) {
            return 0;
	    }

        if (node->left != NULL) {   // if left node got item
            if (node->left->item >= node->item) {   // if left item is bigger than or equal to current item
                return 0;
            }
            else {  // check left subtree whether it is BST
                return isBST(node->left, min, max);     // with the node->left check above. I dont have to worry if I traverse into NULL
            }
        }
        if (node->right != NULL) {
            if (node->right->item <= node->item) {      // if right item is smaller than or equal to current item
                return 0;
            }
            else {  // check right subtree whether it is BST
                return isBST(node->right, min, max);    // with the node->right check above. I dont have to worry if I traverse into NULL
            }
        }
        // if the code reach here, it mean it has reached the leaf child
        return 1;
	} */
	if (node == NULL) {
		return 1;	
	}
	if (node->item >= max || node->item <= min) {	// node should be in between min and max
		return 0;	
	}
	
	return isBst(node->left, min, node->item) && isBst(node->right, node->item, max);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	// write your code here
	BTNode *temp;
	if (node == NULL) { // if tree is empty
        return node;
	}
	if (value < node->item) {   // if value is smaller than current node
        node->left = removeBSTNode(node->left, value);
	}
	else if (value > node->item) {  // if value is bigger than current node
        node->right = removeBSTNode(node->right, value);
	}
	else {  // node = value
        if (node->left == NULL && node->right == NULL) {    // if node is a leaf child
            free(node);
            return NULL;
        }
        else if (node->left != NULL && node->right == NULL) {  // if node only have left child
            temp = node->left;
            free(node);
            return temp;
        }
        else if (node->left == NULL && node->right != NULL) {   // if node only have right child
            temp = node->right;
            free(node);
            return temp;
        }
        else {  // node have both child
            temp = findMin(node->right);    // find the min in the right subtree
            if (temp == NULL) {
                return node;
            }
            node->item = temp->item;
            node->right = removeBSTNode(node->right, temp->item);
        }
	}
	return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	// write your code here
	if (p == NULL) {
        return NULL;
	}
	if (p->left != NULL) {
        return findMin(p->left);
	}
	else {
        return p;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
