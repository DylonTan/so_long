#include "so_long.h"

void	render_player(t_game *game)
{
	if (game->player->direction == -1)
		draw_on_img(game->map->obj, game->player->left_obj,
			game->player->x * game->player->left_obj->width,
			game->player->y * game->player->left_obj->height);
	else
		draw_on_img(game->map->obj, game->player->right_obj,
			game->player->x * game->player->right_obj->width,
			game->player->y * game->player->right_obj->height);
}
