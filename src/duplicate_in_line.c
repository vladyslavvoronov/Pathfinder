#include "pathfinder.h"

void duplicate_in_line(t_vertex *vert, int *line) {
    *line = 2;

    for (int i = 0; i <= vert->count_vert - 3; i += 3) {
        if (mx_strcmp(vert->dist[i], vert->dist[i + 1]) == 0)
            print_invalid_line(line);
        (*line)++;
    }
}
