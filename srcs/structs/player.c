#include "so_long.h"

t_player	*init_player(t_game *game)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player));
	player->left_obj = init_obj();
	player->left_obj->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/player_left.xpm", &(player->left_obj->width),
			&(player->left_obj->height));
	player->left_obj->addr = mlx_get_data_addr(player->left_obj->img,
			&(player->left_obj->bits_per_pixel),
			&(player->left_obj->line_length),
			&(player->left_obj->endian));
	filter_transparent(game, player->left_obj);
	player->right_obj = init_obj();
	player->right_obj->img = mlx_xpm_file_to_image(game->mlx,
			"./srcs/assets/player_right.xpm", &(player->right_obj->width),
			&(player->right_obj->height));
	player->right_obj->addr = mlx_get_data_addr(player->right_obj->img,
			&(player->right_obj->bits_per_pixel),
			&(player->right_obj->line_length),
			&(player->right_obj->endian));
	filter_transparent(game, player->right_obj);
	player->x = -1;
	player->y = -1;
	player->direction = 1;
	return (player);
}
