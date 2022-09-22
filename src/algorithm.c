#include "pathfinder.h"

static void fill_dist(t_chart *chart, t_vertex *vert) {
    chart->dist_mat = (long **)malloc(sizeof(long *) * vert->count_s_vert);
    for (int h = 0; h < vert->count_s_vert; h++) {
        chart->dist_mat[h] = (long *)malloc(sizeof(long) *
        vert->count_s_vert
);
    }
    for (int i = 0; i < vert->count_s_vert; i++)
        for (int j = 0; j < vert->count_s_vert
; j++)
            chart->dist_mat[i][j] = chart->adj_chart[i][j];
}

void algorithm(t_chart *chart, t_vertex *vert) {
    fill_dist(chart, vert);
    for (int i = 0; vert->s_vert[i]; i++) {
        for (int j = 0; vert->s_vert[j]; j++) {
            for (int n = 0; vert->s_vert[n]; n++) {
                if (chart->adj_chart[j][n] > chart->adj_chart[j][i] +
                    chart->adj_chart[i][n]) {
                        chart->adj_chart[j][n] = chart->adj_chart[j][i] +
                        chart->adj_chart[i][n];
                        chart->path_chart[j][n] = i;
                }
            }
        }
    }
    for (int i = 0; i < vert->count_s_vert; i++) {
        for (int j = 0; j < vert->count_s_vert; j++) {
            if (i < j) {
                output(chart, vert, i, j);
            }
        }
    }
}
