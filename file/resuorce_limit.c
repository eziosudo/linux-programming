#include "sys/types.h"
#include "sys/resource.h"
#include "sys/time.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void work() {
    FILE *f;
    int i;
    double x = 4.5;

    f = tmpfile();
    for (i = 0; i < 10000; ++i) {
        fprintf(f, "Do some output\n");
        if (ferror(f)) {
            fprintf(stderr, "Error writing to temporary file\n");
            exit(1);
        }
    }
    for (i = 0; i < 1000000; ++i) {
        x = log(x * x + 3.21);
    }
}

//int main() {
int resource_limit() {
    struct rusage r_usage;
    struct rlimit r_limit;
    int priority;

    work();
    getrusage(RUSAGE_SELF, &r_usage);

//    priority("CPU usage: User = %ld.%06ld, System = %ld.")

}
