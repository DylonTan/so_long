#include "so_long.h"

void	handle_collect_collectible(t_game *game)
{
	t_collectible	*collectible;

	collectible = get_collectible(game->collectibles_head,
			game->player->x, game->player->y);
	if (collectible && collectible->is_collected == 0)
	{
		collectible->is_collected = 1;
		game->map->collectibles_left--;
	}
}
