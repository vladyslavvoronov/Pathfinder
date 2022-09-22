#include "pathfinder.h"

static int check_tops(int n, t_chart *chart, t_route *troute) {
	int i = troute->route[troute->size];
	int j = troute->route[0];

	if (i != n) {
		if (chart->dist_mat[i][n] == chart->adj_chart[j][i] -
            chart->adj_chart[j][n])
			return 1;
	}
	return 0;
}

static void print_route(t_vertex *vert, t_route *troute) {
	mx_printstr("Route: ");
	for (int i = 1; i <= troute->size; i++) {
		mx_printstr(vert->s_vert[troute->route[i]]);
		if (i < troute->size)
			mx_printstr(" -> ");
		else {
			mx_printstr("\n");
			mx_printstr("Distance: ");
		}
	}
}

static void print_math_sym(t_chart *chart, t_route *troute, int sum) {
	for (int i = 1; i < troute->size; i++){
		mx_printint(chart->dist_mat[troute->route[i]][troute->route[i + 1]]);
		sum += chart->dist_mat[troute->route[i]][troute->route[i + 1]];
		if (i < troute->size - 1)
			mx_printstr(" + ");
		else if (i != 1){
			mx_printstr(" = ");
			mx_printint(sum);
		}
	}
}

void print_output(t_chart *chart, t_vertex *vert, t_route *troute) {
    int len = vert->count_s_vert;
	int sum = 0;

	if (troute->route[troute->size] == troute->route[0]) {
		print_path(vert, troute);
    	print_route(vert, troute);
		print_math_sym(chart, troute, sum);
			mx_printstr("\n");
		print_equally();
	}
	else {
		for (int i = 0; i < len; i++)
			if(check_tops(i, chart, troute)) {
				if (troute->size < troute->count) {
					troute->size++;
					troute->route[troute->size] = i;
				}
				print_output(chart, vert, troute);
				if(troute->size > 1)
					troute->size--;
			}
	}
}
