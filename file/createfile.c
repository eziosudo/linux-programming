#include "stdio.h"

int createFile() {
    int X = 1024 * 1024 - 1;
    FILE *fp = fopen("file.in", "w");
    fseek(fp, X, SEEK_SET);
    fputc('\0', fp);
    fclose(fp);
}

