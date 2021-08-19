#include "so_long.h"

void	render_collectibles(t_game *game)
{
	t_collectible	*head;

	head = *(game->collectibles_head);
	while (head)
	{
		if (head->is_collected == 0)
			draw_on_img(game->map->obj, game->collectible,
				head->x * game->collectible->width,
				head->y * game->collectible->height);
		else if (game->player->x == head->x && game->player->y == head->y)
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
		else
			draw_on_img(game->map->obj, game->floor,
				head->x * game->floor->width, head->y * game->floor->height);
		head = head->next;
	}
}
