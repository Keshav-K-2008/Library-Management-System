#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define FILENAME "library.dat"

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

void displayMenu() {
    printf("\n===== LIBRARY MENU =====\n");
    printf("1. Add Book\n2. Display Books\n3. Search Book\n");
    printf("4. Issue Book\n5. Return Book\n6. Delete Book\n7. Save & Exit\n");
}

void addBook() {
    char title[MAX_TITLE], author[MAX_AUTHOR];
    int year;
    printf("\nEnter Title: "); fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = 0;
    printf("Enter Author: "); fgets(author, MAX_AUTHOR, stdin);
    author[strcspn(author, "\n")] = 0;
    printf("Enter Year: "); scanf("%d", &year); getchar();

    Book *b = createBook(nextId++, title, author, year, 0);
    if (!b) return;

    if (!head) head = b;
    else {
        Book *t = head;
        while (t->next) t = t->next;
        t->next = b;
    }
    printf("\nBook Added! ID: %d\n", b->id);
}

void displayBooks() {
    if (!head) { printf("\nNo Books!\n"); return; }

    printf("\n%-5s %-25s %-25s %-6s %-10s\n", "ID", "Title", "Author", "Year", "Status");
    Book *t = head; int c = 0;
    while (t) {
        printf("%-5d %-25s %-25s %-6d %-10s\n",
            t->id, t->title, t->author, t->year,
            t->isIssued ? "Issued" : "Available");
        c++; t = t->next;
    }
    printf("Total: %d\n", c);
}

void searchBook() {
    int ch; printf("\n1. Search by ID\n2. Search by Title\nChoice: ");
    scanf("%d", &ch); getchar();

    if (ch == 1) {
        int id; printf("Enter ID: "); scanf("%d", &id); getchar();
        Book *t = head;
        while (t) {
            if (t->id == id) {
                printf("\nFound: %s (%s)\n", t->title, t->author);
                return;
            }
            t = t->next;
        }
        printf("\nNot Found!\n");

    } else {
        char title[MAX_TITLE];
        printf("Enter Title: "); fgets(title, MAX_TITLE, stdin);
        title[strcspn(title, "\n")] = 0;
        Book *t = head; int f = 0;

        while (t) {
            if (strstr(t->title, title)) {
                if (!f) printf("\nMatches:\n");
                printf("%d - %s\n", t->id, t->title);
                f = 1;
            }
            t = t->next;
        }
        if (!f) printf("\nNo Match!\n");
    }
}

void issueBook() {
    int id; printf("\nEnter ID to Issue: "); scanf("%d", &id); getchar();
    Book *t = head;
    while (t) {
        if (t->id == id) {
            if (t->isIssued) printf("\nAlready Issued!\n");
            else { t->isIssued = 1; printf("\nIssued: %s\n", t->title); }
            return;
        }
        t = t->next;
    }
    printf("\nNot Found!\n");
}

void returnBook() {
    int id; printf("\nEnter ID to Return: "); scanf("%d", &id); getchar();
    Book *t = head;
    while (t) {
        if (t->id == id) {
            if (!t->isIssued) printf("\nNot Issued!\n");
            else { t->isIssued = 0; printf("\nReturned: %s\n", t->title); }
            return;
        }
        t = t->next;
    }
    printf("\nNot Found!\n");
}

void deleteBook() {
    int id; printf("\nEnter ID to Delete: "); scanf("%d", &id); getchar();

    Book *t = head, *p = NULL;
    while (t) {
        if (t->id == id) {
            if (!p) head = t->next;
            else p->next = t->next;
            printf("\nDeleted: %s\n", t->title);
            free(t); return;
        }
        p = t; t = t->next;
    }
    printf("\nNot Found!\n");
}

void saveToFile() {
    FILE *fp = fopen(FILENAME, "wb");
    if (!fp) return;
    fwrite(&nextId, sizeof(int), 1, fp);

    Book *t = head;
    while (t) {
        fwrite(t, sizeof(Book), 1, fp);
        t = t->next;
    }
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return;

    fread(&nextId, sizeof(int), 1, fp);
    Book temp, *tail = NULL;

    while (fread(&temp, sizeof(Book), 1, fp)) {
        Book *b = createBook(temp.id, temp.title, temp.author, temp.year, temp.isIssued);
        if (!head) head = tail = b;
        else { tail->next = b; tail = b; }
    }
    fclose(fp);
}

void freeMemory() {
    Book *t = head;
    while (t) {
        Book *n = t->next;
        free(t);
        t = n;
    }
}

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
