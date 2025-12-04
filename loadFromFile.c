void loadFromFile() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return;

    fread(&nextId, sizeof(int), 1, fp);
    Book temp, *tail = NULL;

    while (fread(&temp, sizeof(Book), 1, fp)) {
        Book *b = createBook(temp.id, temp.title, temp.author, temp.year, temp.isIssued);
        if (!head) head = tail = b;
        else { tail->next = b; tail = b; }
    }
    fclose(fp);
}