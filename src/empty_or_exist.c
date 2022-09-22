#include "pathfinder.h"

void empty_or_exist(char *argv) {
    int fd = open(argv, O_RDONLY);
    char buf[1];
    int flen = 0;
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" does not exist\n");
        close(fd);
        exit(1);
    }
    for(;read(fd, buf, 1); flen++);
    if (flen <= 0) {
        mx_printerr("error: file ");
        mx_printerr(argv);
        mx_printerr(" is empty\n");
        close(fd);
        exit(1);
    }
}
