#include "pathfinder.h"

void print_invalid_line(int *line) {
    char *count;

    count = mx_itoa((int)(*line));
    mx_printerr("error: line ");
    mx_printerr(count);
    mx_printerr(" is not valid\n");
    if (count)
        free(count);
    exit(1);
}
