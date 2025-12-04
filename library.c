#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define FILENAME "library.csv"

typedef struct Book {
    int id, year, isIssued;
    char title[MAX_TITLE], author[MAX_AUTHOR];
    struct Book *next;
} Book;

Book *head = NULL;
int nextId = 1;

Book* createBook(int id, char *title, char *author, int year, int isIssued) {
    Book *b = (Book*)malloc(sizeof(Book));
    if (!b) return NULL;
    b->id = id; b->year = year; b->isIssued = isIssued;
    strcpy(b->title, title); strcpy(b->author, author);
    b->next = NULL; return b;
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
    int ch; loadFromFile();
    printf("\n=== LIBRARY MANAGEMENT SYSTEM ===\n");

    while (1) {
        displayMenu();
        printf("Choice: "); scanf("%d", &ch); getchar();

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
