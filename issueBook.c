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