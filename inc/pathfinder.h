#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

#define MAX 2147483647

typedef struct s_route {
    int *route;
    int size;
    int count;
} t_route;

typedef struct s_vertex {
    char **dist; //isl_dist
    char **s_vert;
    int digit;
    int count_vert;
    int count_s_vert;
    long sum_bridges;
}   t_vertex;

typedef struct t_chart {
    long **dist_mat;
    long **adj_chart;
    int **path_chart;
    int *dist_path;
} t_chart;

void err(int argc, char **argv, t_vertex *vert);
void empty_or_exist(char *argv);
char *first_line_err(int *line, char *str, t_vertex *vert);
void invalid_line(int *line, char *str);
void invalid_number_of_island(t_vertex *vert, char *str);
void duplicate_in_line(t_vertex *vert, int *line);
void duplicate(t_vertex *vert);
void length_too_big(t_vertex *vert);
void print_invalid_line(int *line);
void del_struct(t_vertex *vert, t_chart *chart);
void create_chart(t_vertex *vert, t_chart *chart);
void adjacent_chart(t_vertex *vert, t_chart *chart);
void chart_path(t_chart *chart, t_vertex *vert);
void algorithm(t_chart *chart, t_vertex *vert);
void output(t_chart *chart, t_vertex *vert, int i, int j);
void print_equally();
void print_path(t_vertex *vert, t_route *t_route);
void print_output(t_chart *chart, t_vertex *vert, t_route *t_route);

#endif
