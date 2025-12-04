#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id, year, isIssued;
    char title[100], author[100];
} Book;

Book books[10000];
int bookCount = 0;
int nextId = 1;

void createBook(int id, char title[100], char author[100], int year, int isIssued) {
    if (bookCount >= 10000) return;
    books[bookCount].id = id;
    books[bookCount].year = year;
    books[bookCount].isIssued = isIssued;
    strcpy(books[bookCount].title, title);
    strcpy(books[bookCount].author, author);
    bookCount++;
}

#include "addbook.c"
#include "deleteBook.c"
#include "displayBooks.c"
#include "displaymenu.c"
#include "freeMemory.c"
#include "issueBook.c"
#include "loadFromFile.c"
#include "returnBook.c"
#include "saveToFile.c"
#include "searchBook.c"
int main() {
    int ch; 
    loadFromFile();
    printf("\n=== LIBRARY MANAGEMENT SYSTEM ===\n");

    while (1) {
        displayMenu();
        printf("Choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: saveToFile(); freeMemory();
                    printf("\nSaved & Exiting...\n"); return 0;
            default: printf("\nInvalid!\n");
        }
    }
}
