#include "pathfinder.h"

static int vertex_index(char *tvertex, t_vertex *vert) {
    for (int i = 0; vert->s_vert[i]; i++)
        if (mx_strcmp(tvertex, vert->s_vert[i]) == 0)
            return i;
    return 0;
}

void adjacent_chart(t_vertex *vert, t_chart *chart) {
    int row;
    int column;

    for (int i = 0; vert->dist[i]; i += 3) {
        row = vertex_index(vert->dist[i], vert);
        column = vertex_index(vert->dist[i + 1], vert);
        chart->adj_chart[row][column] = mx_atoi(vert->dist[i + 2]);
        chart->adj_chart[column][row] = chart->adj_chart[row][column];
    }
}
