#include "pathfinder.h"

char *first_line_err(int *line, char *str, t_vertex *vert) {
    int j = 0;

    if (str[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        free(str);
        exit(1);
    }
    if (mx_atoi(str) == 1 && vert->dist) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    for (;str[j] != '\n'; j++) {
        if (!mx_isdigit(str[j])) {
            mx_printerr("error: line 1 is not valid\n");
            free(str);
            exit(1);
        }
    }
    (*line) += 1;
    return str + j + 1;
}
