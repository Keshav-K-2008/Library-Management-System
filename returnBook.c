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