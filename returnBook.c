void returnBook() {
    int id; printf("\nEnter ID to Return: "); scanf("%d", &id); getchar();
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (!books[i].isIssued) printf("\nNot Issued!\n");
            else { books[i].isIssued = 0; printf("\nReturned: %s\n", books[i].title); }
            return;
        }
    }
    printf("\nNot Found!\n");
}