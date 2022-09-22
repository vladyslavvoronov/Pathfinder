#include "pathfinder.h"

static void dot_comma(int *line, char *str) {
    int i;

    for (i = 0; str[i] != '\n'; i++) {
        if (str[i] == '-' && (!mx_isalpha(str[i - 1]) || !mx_isalpha(str[i + 1])))
            print_invalid_line(line);
    }
    for (i = 0; str[i] != '\n'; i++) {
        if (str[i] == ',' && (!mx_isalpha(str[i - 1]) || !mx_isdigit(str[i + 1])))
            print_invalid_line(line);
    }
}

void invalid_line(int *line, char *str) {
    int i;

    if (*str != '\0') {
        if (str[0] == '\n')
            print_invalid_line(line);
        dot_comma(line, str);
        for (i = 0; str[i] != '-'; i++) {
            if (!mx_isalpha(str[i]))
                print_invalid_line(line);
        }
        for (i += 1; str[i] != ','; i++) {
            if (!mx_isalpha(str[i]))
                print_invalid_line(line);
        }
        for (i += 1; str[i] != '\n'; i++) {
            if (!mx_isdigit(str[i]))
                print_invalid_line(line);
        }
    (*line) += 1;
    i += 1;
    invalid_line(line, str + i);
    }
}
