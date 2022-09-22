#include "pathfinder.h"

void create_chart(t_vertex *vert, t_chart *chart) {
    chart->adj_chart = (long **)malloc(sizeof(long *) * vert->count_s_vert);
    for (int h = 0; h < vert->count_s_vert; h++) {
        chart->adj_chart[h] = (long *)malloc(sizeof(long) *
        vert->count_s_vert);
    }
    for (int i = 0; i < vert->count_s_vert; i++) {
        for (int j = 0; j < vert->count_s_vert; j++) {
            chart->adj_chart[i][j] = MAX;
            if (i == j)
                chart->adj_chart[i][j] = 0;
        }
    }
}
