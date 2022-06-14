#include "unistd.h"
#include "stdlib.h"


char *get_current_dir_name() {
    long size = 256;
    char *buf;
    char *ptr = NULL;
    if ((buf = (char *) malloc((size_t) size)) != NULL) {
        ptr = getcwd(buf, (size_t) size);
    }
    return ptr;
}
