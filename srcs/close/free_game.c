#include "so_long.h"

void	free_game_items(t_game *game)
{
	if (game->exit)
		free_exit(game->exit);
	if (game->player)
		free_player(game->player);
	if (game->collectibles_head)
		free_collectibles(game->collectibles_head);
	if (game->enemies_head)
		free_enemies(game->enemies_head);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_game_items(game);
	if (game->collectible)
		free(game->collectible);
	if (game->floor)
		free(game->floor);
	if (game->wall)
		free(game->wall);
	if (game->moves_bg)
		free(game->moves_bg);
	if (game->enemy_left)
		free(game->enemy_left);
	if (game->enemy_right)
		free(game->enemy_right);
	if (game->map->grid)
		free_map_grid(game->map->grid);
	if (game->map->obj)
		free(game->map->obj);
	if (game->map)
		free(game->map);
	if (game->mlx)
		free(game->mlx);
	free(game);
}
