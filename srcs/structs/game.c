#include "so_long.h"

void	init_floor_wall(t_game *game)
{
	game->floor = init_obj();
	game->floor->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/floor.xpm", &(game->floor->width),
			&(game->floor->height));
	game->floor->addr = mlx_get_data_addr(game->floor->img,
			&(game->floor->bits_per_pixel), &(game->floor->line_length),
			&(game->floor->endian));
	game->wall = init_obj();
	game->wall->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/wall.xpm", &(game->wall->width),
			&(game->wall->height));
	game->wall->addr = mlx_get_data_addr(game->wall->img,
			&(game->wall->bits_per_pixel), &(game->wall->line_length),
			&(game->wall->endian));
	filter_transparent(game, game->wall);
	game->moves_bg = init_obj();
	game->moves_bg->img = mlx_new_image(game->mlx, 80, 12);
	game->moves_bg->addr = mlx_get_data_addr(game->moves_bg->img,
			&(game->moves_bg->bits_per_pixel), &(game->moves_bg->line_length),
			&(game->moves_bg->endian));
}

void	init_collectible_enemy(t_game *game)
{
	game->collectible = init_obj();
	game->collectible->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/collectible.xpm", &(game->collectible->width),
			&(game->collectible->height));
	game->collectible->addr = mlx_get_data_addr(game->collectible->img,
			&(game->collectible->bits_per_pixel),
			&(game->collectible->line_length),
			&(game->collectible->endian));
	filter_transparent(game, game->collectible);
	game->enemy_left = init_enemy_left(game);
	filter_transparent(game, game->enemy_left);
	game->enemy_right = init_enemy_right(game);
	filter_transparent(game, game->enemy_right);
}

void	init_game_vars(t_game *game)
{
	game->exit = init_exit(game);
	game->player = init_player(game);
	game->collectibles_head = init_collectibles_head();
	game->enemies_head = init_enemies_head();
	game->moves = 0;
	game->offset_x = 0;
	game->offset_y = 0;
	game->frames = 0;
}

t_game	*init_game(int width, int height)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->win_width = 1920;
	game->win_height = 1080;
	if (width * 64 < 1920)
		game->win_width = width * 64;
	if (height * 64 < 1080)
		game->win_height = height * 64;
	game->win = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "So long");
	init_floor_wall(game);
	init_collectible_enemy(game);
	game->map = init_map();
	game->map->width = width;
	game->map->height = height;
	game->map->obj->img = mlx_new_image(game->mlx,
			game->map->width * 64, game->map->height * 64);
	game->map->obj->addr = mlx_get_data_addr(game->map->obj->img,
			&(game->map->obj->bits_per_pixel), &(game->map->obj->line_length),
			&(game->map->obj->endian));
	init_game_vars(game);
	return (game);
}
