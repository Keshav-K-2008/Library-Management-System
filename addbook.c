void addBook() {
    char title[100], author[100];
    int year;
    printf("\nEnter Title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0;
    printf("Enter Author: ");
    fgets(author, 100, stdin);
    author[strcspn(author, "\n")] = 0;
    printf("Enter Year: ");
    scanf("%d", &year); getchar();

    createBook(nextId++, title, author, year, 0);
    printf("\nBook Added! ID: %d\n", nextId - 1);
}