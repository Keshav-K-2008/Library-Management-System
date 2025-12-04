void displayBooks() {
    if (bookCount == 0) { printf("\nNo Books!\n"); return; }

    printf("\n%-5s %-25s %-25s %-6s %-10s\n", "ID", "Title", "Author", "Year", "Status");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-25s %-25s %-6d %-10s\n",
            books[i].id, books[i].title, books[i].author, books[i].year,
            books[i].isIssued ? "Issued" : "Available");
    }
    printf("Total: %d\n", bookCount);
}