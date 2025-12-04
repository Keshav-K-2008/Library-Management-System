void freeMemory() {
    Book *t = head;
    while (t) {
        Book *n = t->next;
        free(t);
        t = n;
    }
}