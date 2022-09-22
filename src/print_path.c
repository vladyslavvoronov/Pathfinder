#include "pathfinder.h"

void print_path(t_vertex *vert, t_route *troute) {
		print_equally();
		mx_printstr("Path: ");
		mx_printstr(vert->s_vert[troute->route[1]]);
    	mx_printstr(" -> ");
    	mx_printstr(vert->s_vert[troute->route[0]]);
    	mx_printstr("\n");
}
