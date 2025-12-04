void deleteBook() {
    int id; printf("\nEnter ID to Delete: "); scanf("%d", &id); getchar();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("\nDeleted: %s\n", books[i].title);
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            return;
        }
    }
    printf("\nNot Found!\n");
}