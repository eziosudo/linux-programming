#include "unistd.h"
#include "fcntl.h"
#include "../tools.h"
#include "file.h"

//int main() {
int copy_system() {
//    create_file();

    char c;
    int in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    while (read(in, &c, 1) == 1) {
        write(out, &c, 1);
    }
    return 0;
}
