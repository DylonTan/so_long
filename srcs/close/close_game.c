#include "so_long.h"

void	close_mlx_win(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

int	close_game(t_game *game)
{
	if (game->collectible->img)
		mlx_destroy_image(game->mlx, game->collectible->img);
	if (game->floor->img)
		mlx_destroy_image(game->mlx, game->floor->img);
	if (game->wall->img)
		mlx_destroy_image(game->mlx, game->wall->img);
	if (game->exit->obj->img)
		mlx_destroy_image(game->mlx, game->exit->obj->img);
	if (game->enemy_left->img)
		mlx_destroy_image(game->mlx, game->enemy_left->img);
	if (game->enemy_right->img)
		mlx_destroy_image(game->mlx, game->enemy_right->img);
	if (game->moves_bg->img)
		mlx_destroy_image(game->mlx, game->moves_bg->img);
	if (game->player->left_obj->img)
		mlx_destroy_image(game->mlx, game->player->left_obj->img);
	if (game->player->right_obj->img)
		mlx_destroy_image(game->mlx, game->player->right_obj->img);
	if (game->map->obj->img)
		mlx_destroy_image(game->mlx, game->map->obj->img);
	close_mlx_win(game);
	free_game(game);
	exit(0);
	return (1);
}
