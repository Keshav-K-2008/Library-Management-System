void issueBook() {
    int id; printf("\nEnter ID to Issue: "); scanf("%d", &id); getchar();
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued) printf("\nAlready Issued!\n");
            else { books[i].isIssued = 1; printf("\nIssued: %s\n", books[i].title); }
            return;
        }
    }
    printf("\nNot Found!\n");
}