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