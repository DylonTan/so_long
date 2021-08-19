#include "so_long.h"

void	handle_visit_exit(t_game *game)
{
	if (game->map->collectibles_left <= 0)
	{
		printf("YOU WIN!\n");
		close_game(game);
		exit(0);
	}
}
