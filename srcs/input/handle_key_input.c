#include "so_long.h"

void	handle_w_key_input(t_game *game)
{
	if (game->map->grid[game->player->y][game->player->x] == 'E')
		draw_on_img(game->map->obj, game->exit->obj,
			game->player->x * game->exit->obj->width,
			game->player->y * game->exit->obj->height);
	else
		draw_on_img(game->map->obj, game->floor,
			game->player->x * game->player->left_obj->width,
			game->player->y * game->player->right_obj->height);
	if (game->map->grid[game->player->y - 1][game->player->x] != '1')
	{
		game->player->y--;
		game->moves++;
	}
	if ((game->player->y * 64 + game->offset_y) < game->win_height / 2)
		game->offset_y += 64;
	printf("Moves: %d\n", game->moves);
}

void	handle_a_key_input(t_game *game)
{
	if (game->map->grid[game->player->y][game->player->x] == 'E')
		draw_on_img(game->map->obj, game->exit->obj,
			game->player->x * game->exit->obj->width,
			game->player->y * game->exit->obj->height);
	else
		draw_on_img(game->map->obj, game->floor,
			game->player->x * game->player->left_obj->width,
			game->player->y * game->player->right_obj->height);
	if (game->map->grid[game->player->y][game->player->x - 1] != '1')
	{
		game->player->x--;
		game->moves++;
	}
	game->player->direction = -1;
	if ((game->player->x * 64 + game->offset_x) < game->win_width / 2)
		game->offset_x += 64;
	printf("Moves: %d\n", game->moves);
}

void	handle_s_key_input(t_game *game)
{
	if (game->map->grid[game->player->y][game->player->x] == 'E')
		draw_on_img(game->map->obj, game->exit->obj,
			game->player->x * game->exit->obj->width,
			game->player->y * game->exit->obj->height);
	else
		draw_on_img(game->map->obj, game->floor,
			game->player->x * game->player->left_obj->width,
			game->player->y * game->player->right_obj->height);
	if (game->map->grid[game->player->y + 1][game->player->x] != '1')
	{
		game->player->y++;
		game->moves++;
	}
	if ((game->player->y * 64 + game->offset_y) * 2 >= game->win_height)
		game->offset_y -= 64;
	printf("Moves: %d\n", game->moves);
}

void	handle_d_key_input(t_game *game)
{
	if (game->map->grid[game->player->y][game->player->x] == 'E')
		draw_on_img(game->map->obj, game->exit->obj,
			game->player->x * game->exit->obj->width,
			game->player->y * game->exit->obj->height);
	else
		draw_on_img(game->map->obj, game->floor,
			game->player->x * game->player->left_obj->width,
			game->player->y * game->player->right_obj->height);
	if (game->map->grid[game->player->y][game->player->x + 1] != '1')
	{
		game->player->x++;
		game->moves++;
	}
	game->player->direction = 1;
	if ((game->player->x * 64 + game->offset_x) * 2 >= game->win_width)
		game->offset_x -= 64;
	printf("Moves: %d\n", game->moves);
}

int	handle_key_input(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 119)
		handle_w_key_input(game);
	else if (keycode == 97)
		handle_a_key_input(game);
	else if (keycode == 115)
		handle_s_key_input(game);
	else if (keycode == 100)
		handle_d_key_input(game);
	if (game->map->grid[game->player->y][game->player->x] == 'C')
		handle_collect_collectible(game);
	else if (game->map->grid[game->player->y][game->player->x] == 'E')
		handle_visit_exit(game);
	else
		handle_collide_enemy(game);
	return (1);
}
