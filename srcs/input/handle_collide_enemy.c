#include "so_long.h"

void	handle_collide_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = get_enemy(game->enemies_head, game->player->x, game->player->y);
	if (enemy)
	{
		printf("KO\n");
		close_game(game);
	}
}
