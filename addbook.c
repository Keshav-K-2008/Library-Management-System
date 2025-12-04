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