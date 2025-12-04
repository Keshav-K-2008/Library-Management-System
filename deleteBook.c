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