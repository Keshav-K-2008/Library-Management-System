void searchBook() {
    int ch; printf("\n1. Search by ID\n2. Search by Title\nChoice: ");
    scanf("%d", &ch); getchar();

    if (ch == 1) {
        int id; printf("Enter ID: "); scanf("%d", &id); getchar();
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                printf("\nFound: %s (%s)\n", books[i].title, books[i].author);
                return;
            }
        }
        printf("\nNot Found!\n");

    } else {
        char title[100];
        printf("Enter Title: "); fgets(title, 100, stdin);
        title[strcspn(title, "\n")] = 0;
        int f = 0;

        for (int i = 0; i < bookCount; i++) {
            if (strstr(books[i].title, title)) {
                if (!f) printf("\nMatches:\n");
                printf("%d - %s\n", books[i].id, books[i].title);
                f = 1;
            }
        }
        if (!f) printf("\nNo Match!\n");
    }
}