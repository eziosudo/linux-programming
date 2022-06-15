#include "stdio.h"
#include "stdlib.h"

//int main() {
int tmp_file() {
    char tmpname[L_tmpnam];
    char *filename;
    FILE *tmpfp;

    // tmpnam() is deprecated
    filename = tmpnam(tmpname);

    printf("Temporary file name is %s\n", filename);
    tmpfp = tmpfile();
    if (tmpfp) {
        printf("Opened a temporary file OK\n");
    } else {
        perror("tmpfile");
    }
    exit(0);
}