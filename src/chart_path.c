#include "pathfinder.h"

void chart_path(t_chart *chart, t_vertex *vert) {
    chart->path_chart = (int **)malloc(sizeof(int *) * vert->count_s_vert);
    for (int h = 0; vert->s_vert[h]; h++) {
        chart->path_chart[h] = (int *)malloc(sizeof(int) *
        vert->count_s_vert);
    }
    for (int i = 0; i < vert->count_s_vert; i++) {
        for (int j = 0; j < vert->count_s_vert; j++)
            chart->path_chart[i][j] = j;
    }
}
