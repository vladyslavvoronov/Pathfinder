#include "pathfinder.h"

static int* dex_arr(int count) {
	int *arr = (int*)malloc(sizeof(int) * count);
	int i = 0;

	for(; i < count; i++)
		arr[i] = 0;
	return arr;
}

static t_route *create_route(t_vertex *vert, int start, int finish) {
	t_route *troute = (t_route*)malloc(sizeof(t_route));
    int len = vert->count_s_vert;

	if(troute == NULL)
		exit(-1);
	troute->route = dex_arr(len);
	troute->size = 1;
	troute->count = len;
	troute->route[0] = finish;
	troute->route[1] = start;
	return troute;
}

void output(t_chart *chart, t_vertex *vert, int i, int j) {
    t_route *troute = create_route(vert, i, j);
    print_output(chart, vert, troute);
    free(troute->route);
    free(troute);
}
