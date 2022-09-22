#include "pathfinder.h"

void err(int argc, char **argv, t_vertex *vert) {
    int line = 1;
    char *str = NULL;
    char *tmp = NULL;
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    empty_or_exist(argv[1]);
    str = mx_file_to_str(argv[1]);
    tmp = str;
    str = first_line_err(&line, str, vert);
    invalid_line(&line, str);
    str = tmp;
    invalid_number_of_island(vert, str);
    if (str)
        free(str);
    duplicate_in_line(vert, &line);
    duplicate(vert);
    length_too_big(vert);
}
