#include "pathfinder.h"

void duplicate(t_vertex *vert) {
    for (int i = 0; i <= vert->count_vert - 3; i += 3)
        for (int j = i + 3; j <= vert->count_vert - 3; j += 3)
            if ((mx_strcmp(vert->dist[i], vert->dist[j]) == 0) &&
                (mx_strcmp(vert->dist[i + 1], vert->dist[j + 1]) == 0)) {
                    mx_printerr("error: duplicate bridges\n");
                    exit(1);
            }
            else if ((mx_strcmp(vert->dist[i], vert->dist[j + 1]) == 0) &&
                (mx_strcmp(vert->dist[i + 1], vert->dist[j]) == 0)) {
                    mx_printerr("error: duplicate bridges\n");
                    exit(1);
            }
}
