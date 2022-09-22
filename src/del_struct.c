#include "pathfinder.h"

static void del_int_arr(int **arr, int len) {
    if (arr) {
        for (int i = 0; i < len; i++)
            free(arr[i]);
        free(arr);
    }
}
static void del_arr(long **arr, int len) {
    if (arr) {
        for (int i = 0; i < len; i++)
            free(arr[i]);
        free(arr);
    }
}

void del_struct(t_vertex *vert, t_chart *chart) {
    if (vert->dist)
        mx_del_strarr(&vert->dist);
    if (vert->s_vert)
        mx_del_strarr(&vert->s_vert);
    if (chart->dist_mat)
        del_arr(chart->dist_mat, vert->count_s_vert);
    if (chart->adj_chart)
        del_arr(chart->adj_chart, vert->count_s_vert);
    if (chart->path_chart)
        del_int_arr(chart->path_chart, vert->count_s_vert);
    if (vert)
        free(vert);
    if (chart)
        free(chart);
}

