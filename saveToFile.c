void saveToFile() {
    FILE *fp = fopen("library.csv", "w");
    if (!fp) return;
    fprintf(fp, "ID,Title,Author,Year,IsIssued\n");

    for (int i = 0; i < bookCount; i++) {
        fprintf(fp, "%d,\"%s\",\"%s\",%d,%d\n", books[i].id, books[i].title, books[i].author, books[i].year, books[i].isIssued);
    }
    fclose(fp);
}