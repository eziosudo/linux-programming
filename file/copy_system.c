#include "unistd.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "file.h"

int main() {
    createFile();

    char c;
    int in, out;

    in = open("file.in", O_RDONLY);
    out = ("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    while (read(in, &c, 1) == 1) {
        write(out, &c, 1);
    }
    exit(0);
}