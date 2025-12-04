void saveToFile() {
    FILE *fp = fopen(FILENAME, "wb");
    if (!fp) return;
    fwrite(&nextId, sizeof(int), 1, fp);

    Book *t = head;
    while (t) {
        fwrite(t, sizeof(Book), 1, fp);
        t = t->next;
    }
    fclose(fp);
}