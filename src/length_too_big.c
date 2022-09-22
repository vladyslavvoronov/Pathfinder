#include "pathfinder.h"

void length_too_big(t_vertex *vert) {
    vert->sum_bridges = 0;

    for (int i = 2; i <= vert->count_vert - 1; i += 3) {
        vert->sum_bridges += mx_atoi(vert->dist[i]);
    }
    if (vert->sum_bridges > 2147483647) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }
}
