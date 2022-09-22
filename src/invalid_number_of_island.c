#include "pathfinder.h"

static int countlen(int n) {
    int len_number = 1;
    
    while(n /= 10)
        len_number++;
    return len_number;
}

static int strsplifPf(const char *str, char del) {
    int s1 = 0;
    int s2 = 0;

    if (!str)
        return -1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == del) {
            s1 = 0;
        }
        else if (s1 == 0) {
            ++s2;
            s1 = 1;
        }
    }
    return s2;
}

static void sort_arr_vertex(t_vertex *vert) {
    vert->count_s_vert = 1;
    vert->s_vert = (char **)malloc(sizeof(char *) * vert->count_vert);
    vert->s_vert[0] = mx_strdup(vert->dist[0]);
    vert->s_vert[1] = NULL;

    if (vert->s_vert[0]) {
        for (int i = 1; vert->dist[i]; i++) {
            if (mx_isdigit(vert->dist[i][0]))
                continue;
            for (int j = 0; vert->s_vert[j]; j++) {
                if (mx_strcmp(vert->dist[i], vert->s_vert[j]) == 0)
                    break;
                if (mx_strcmp(vert->dist[i], vert->s_vert[j]) != 0 &&
                    vert->s_vert[j + 1] == NULL) {
                    vert->s_vert[j + 1] = mx_strdup(vert->dist[i]);
                    vert->s_vert[j + 2] = NULL;
                    vert->count_s_vert += 1;
                }
            }
        }
    }
}

void invalid_number_of_island(t_vertex *vert, char *str) {
    int i;

    if (*str != '\0') {
        for (i = 0; str[i] != '\n'; i++) {
            if (mx_isdigit(str[i]))
                vert->digit = mx_atoi(str);
        }
        str += countlen(vert->digit);
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] == '-' || str[i] == ',' || str[i] == '\n')
                str[i] = ' ';
        }
        vert->count_vert = strsplifPf(str, ' ');
        vert->dist = mx_strsplit(str, ' ');
        sort_arr_vertex(vert);
    }
    if (vert->count_s_vert == 1 && vert->digit == 0)
        exit(0);
    if (vert->count_s_vert != vert->digit) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
