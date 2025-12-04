void searchBook() {
    int ch; printf("\n1. Search by ID\n2. Search by Title\nChoice: ");
    scanf("%d", &ch); getchar();

    if (ch == 1) {
        int id; printf("Enter ID: "); scanf("%d", &id); getchar();
        Book *t = head;
        while (t) {
            if (t->id == id) {
                printf("\nFound: %s (%s)\n", t->title, t->author);
                return;
            }
            t = t->next;
        }
        printf("\nNot Found!\n");

    } else {
        char title[MAX_TITLE];
        printf("Enter Title: "); fgets(title, MAX_TITLE, stdin);
        title[strcspn(title, "\n")] = 0;
        Book *t = head; int f = 0;

        while (t) {
            if (strstr(t->title, title)) {
                if (!f) printf("\nMatches:\n");
                printf("%d - %s\n", t->id, t->title);
                f = 1;
            }
            t = t->next;
        }
        if (!f) printf("\nNo Match!\n");
    }
}