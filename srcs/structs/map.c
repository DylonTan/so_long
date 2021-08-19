#include "so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->obj = init_obj();
	map->collectibles_left = 0;
	return (map);
}
