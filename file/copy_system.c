#include <stdio.h>
#include "unistd.h"
#include "fcntl.h"
#include "../tools.h"
#include "file.h"

int main() {
//int copy_system() {
//    create_file();

//    char c;
    int c;
//    int in, out;
    FILE *in, *out;

//    in = open("file.in", O_RDONLY);
//    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    in = fopen("file.in", "r");
    out = fopen("file.out", "w");

//    while (read(in, &c, 1) == 1) {
//        write(out, &c, 1);
//    }
    while ((c = fgetc(in)) != EOF){
        fputc(c, out);
    }
    return 0;
}
