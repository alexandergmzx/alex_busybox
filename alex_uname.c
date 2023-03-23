#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <sys/utsname.h>

int main(void) {

    struct utsname system_info;
    // char *p;
    // int release_arr[16];
    // int i=0;

    if (uname(&system_info) != 0) {
        perror("Error calling uname");
        exit(1);
    }

    printf("System name             = %s\n", system_info.sysname);
    // printf("Node name               = %s\n", system_info.nodename);
    printf("Release                 : %s\n", system_info.release);

    //To print more detailed the release:
    // p = system_info.release;
    // while (*p) {
    //     if (isdigit(*p)) {
    //         release_arr[i] = strtol(p, &p, 10);
    //         i++;
    //     } else {
    //         p++;
    //     }
    // }

    // printf("Kernel=%d Major Version=%d Minor Version=%d Patch=%d\n", release_arr[0], release_arr[1], release_arr[2], release_arr[3]);

    printf("Version                 = %s\n", system_info.version);
    printf("Processor type/Machine  = %s\n", system_info.machine);


    return 0;
}