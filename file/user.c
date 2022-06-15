#include "stdio.h"
#include "sys/types.h"
#include "pwd.h"
#include "unistd.h"
#include "stdlib.h"

int main() {
    uid_t uid;
    gid_t gid;
    struct passwd *pw;
    uid = getuid();
    gid = getgid();

    printf("User is %s\n", getlogin());
    printf("User Ids, uid=%d, gid=%d", uid, gid);

    pw = getpwuid(uid);
    printf("User IDs, uid=%d, gid=%d, home=%s,shell=%s\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir,
           pw->pw_shell);

    pw = getpwnam("root");
    printf("root password entry:\n");
    printf("uid=%d, gid=%d, home=%s,shell=%s\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir,
           pw->pw_shell);
    exit(0);
}