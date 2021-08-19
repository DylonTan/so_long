#include "so_long.h"

t_obj	*init_enemy_right(t_game *game)
{
	t_obj	*enemy;

	enemy = init_obj();
	enemy->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/enemy_right.xpm", &(enemy->width), &(enemy->height));
	enemy->addr = mlx_get_data_addr(enemy->img, &(enemy->bits_per_pixel),
			&(enemy->line_length), &(enemy->endian));
	return (enemy);
}

t_obj	*init_enemy_left(t_game *game)
{
	t_obj	*enemy;

	enemy = init_obj();
	enemy->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/enemy_left.xpm", &(enemy->width), &(enemy->height));
	enemy->addr = mlx_get_data_addr(enemy->img, &(enemy->bits_per_pixel),
			&(enemy->line_length), &(enemy->endian));
	return (enemy);
}
