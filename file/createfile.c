#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "../tools.h"

int create_file() {
    char *cur_dir = get_current_dir_name();
    printf("%s\n", cur_dir);
    FILE *fp = fopen(strcat(cur_dir, "/file.in"), "w");
    if (fp == NULL) {
        printf("fopen error\n");
        exit(1);
    }
    printf("create file success\n");
    char *str = "fillfile";
//    printf("len(str): %d\n", strlen(str));

    // create a 1M file
    for (int i = 0; i < 128 * 1024; ++i) {
        fwrite(str, sizeof(char), strlen(str), fp);
    }

    fclose(fp);
    free(cur_dir);
    free(str);
    return 0;
}

