void loadFromFile() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) return;

    char line[300];
    fgets(line, sizeof(line), fp); 
    
    Book *tail = NULL;
    char title[MAX_TITLE], author[MAX_AUTHOR];
    int id, year, isIssued;
    int maxId = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,\"%99[^\"]\",\"%99[^\"]\"%*[,]%d,%d", &id, title, author, &year, &isIssued) == 5) {
            Book *b = createBook(id, title, author, year, isIssued);
            if (!head) head = tail = b;
            else { tail->next = b; tail = b; }
            if (id > maxId) maxId = id;
        }
    }
    fclose(fp);
    nextId = maxId + 1;
}