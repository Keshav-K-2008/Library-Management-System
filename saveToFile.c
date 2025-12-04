void saveToFile() {
    FILE *fp = fopen(FILENAME, "w");
    if (!fp) return;
    fprintf(fp, "ID,Title,Author,Year,IsIssued\n");

    Book *t = head;
    while (t) {
        fprintf(fp, "%d,\"%s\",\"%s\",%d,%d\n", t->id, t->title, t->author, t->year, t->isIssued);
        t = t->next;
    }
    fclose(fp);
}