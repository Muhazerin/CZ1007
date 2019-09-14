#include <stdio.h>
#define SIZE 20
typedef struct {
    char title[81];
    char lastname[81];
    char firstname[81];
    char publisher[81];
    int day, month, year;
} Booktype;
void readBook(Booktype *book);
void printBook(Booktype book);
int main(){
    Booktype book[SIZE];
    char repeat = 'y',size=0;

    do {
        readBook(&book[size]);
        printf("The book information:\n");
        printBook(book[size]);
        printf("Continue ('y' or 'n'): ");
        scanf("%c", &repeat);
        size++;
    } while (repeat == 'y');
    return 0;
}
void readBook(Booktype *book)
{
    static int i;
    char temp;

    puts("Enter the title of the book: ");
    if (i > 0) {
        scanf("%c", &temp);
    }
    gets(book->title);
    puts("Enter the author's first name: ");
    gets(book->firstname);
    puts("Enter the author's last name: ");
    gets(book->lastname);
    puts("Enter date as (dd-mm-yy): ");
    scanf("%d-%d-%d", &book->day, &book->month, &book->year);
    puts("Enter the publisher name: ");
    scanf("%c", &temp);
    gets(book->publisher);
    i++;
}
void printBook(Booktype book)
{
    printf("Title: %s\n", book.title);
    printf("Author: %s %s\n", book.firstname, book.lastname);
    printf("Date: %d-%d-%d\n", book.day, book.month, book.year);
    printf("Publisher: %s\n", book.publisher);
}
