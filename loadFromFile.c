void loadFromFile() {
    FILE *fp = fopen("library.csv", "r");
    if (!fp) return;

    char line[300];
    fgets(line, sizeof(line), fp);
    
    char title[100], author[100];
    int id, year, isIssued;
    int maxId = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,\"%99[^\"]\",\"%99[^\"]\"%*[,]%d,%d", &id, title, author, &year, &isIssued) == 5) {
            createBook(id, title, author, year, isIssued);
            if (id > maxId) maxId = id;
        }
    }
    fclose(fp);
    nextId = maxId + 1;
}