#include "so_long.h"

t_exit	*init_exit(t_game *game)
{
	t_exit	*exit;

	exit = (t_exit *) malloc(sizeof(t_exit));
	exit->x = -1;
	exit->y = -1 ;
	exit->is_visited = 0;
	exit->obj = init_obj();
	exit->obj->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/exit.xpm", &(exit->obj->width),
			&(exit->obj->height));
	exit->obj->addr = mlx_get_data_addr(exit->obj->img,
			&(exit->obj->bits_per_pixel), &(exit->obj->line_length),
			&(exit->obj->endian));
	filter_transparent(game, exit->obj);
	return (exit);
}
