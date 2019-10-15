// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists
// Template for Q1

#include "stdlib.h"
#include "stdio.h"

////////////////////////////////////////////////////////////

void insert(char *s,int n);
void removes(char *s, int n);

//////////////////////////////////////////////////////////
int main ()
{
	int n;
    char *s;
	int choice;


	printf("How many characters do you want to input: ");
	scanf("%d", &n);

	s=(char *)malloc((n+1)*sizeof(char));

    if (s==NULL)
	{
		printf("can't allocate the memory!");
		return 1;
	}

	printf("Input the string: ");
	scanf("%s",s);

	printf("The string is %s\n", s);

	do
	{
		printf("Do you want to 1-insert or 2-remove or 3-quit?: ");
		scanf("%d",&choice);
		//getchar(); //to clear the return carriage in the buffer

		if (choice==1)
			insert(s,n);
		else if (choice==2)
			removes(s,n);
	}while (choice!=3);

    free(s);
    return 0;
}

//////////////////////////////////////////
void removes(char *s, int n)
{
	// write your code here
    char *t;
    int i;
    t = (char *)malloc(n * sizeof(char));

    for (i = 0; i < n-1; i++) {
        *(t+i) = *(s+i);
    }
    *(t+i) = '\0';
    printf("Resulting string: %s\n", t);

    free(t);
}

//////////////////////////////////////////
void insert(char *s, int n)
{
	// write your code here
	int i;
	char *t;

	t = (char *)malloc((n+1) * sizeof(char));

	printf("What is the character you want to insert: ");
	scanf("\n%c", t);
	for (i = 1; i < n; i++) {
        *(t+i) = *(s+i-1);
	}
	*(t+i) = '\0';
	printf("Resulting string: %s\n", t);

	free(t);
}
