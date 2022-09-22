#include "pathfinder.h"

int main(int argc, char *argv[]) {
	t_vertex *vert = (t_vertex*)malloc(sizeof(t_vertex));
	t_chart *chart = (t_chart*)malloc(sizeof(t_chart));

	err(argc, argv, vert);
	create_chart(vert, chart);
	adjacent_chart(vert, chart);
	chart_path(chart, vert);
	algorithm(chart, vert);
	del_struct(vert, chart);
	return 0;
}
