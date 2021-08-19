#include "so_long.h"

void	set_dynamic_items(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'C')
	{
		set_collectible(game->collectibles_head, x, y);
		game->map->collectibles_left++;
	}
	else if (game->map->grid[y][x] == 'P')
	{
		game->player->x = x;
		game->player->y = y;
	}
}

void	draw_static_img(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == '1')
		draw_on_img(game->map->obj, game->wall,
			x * game->wall->width, y * game->wall->height);
	else if (game->map->grid[y][x] == 'E')
		draw_on_img(game->map->obj, game->exit->obj,
			x * game->exit->obj->width, y * game->exit->obj->height);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			draw_on_img(game->map->obj, game->floor,
				x * game->floor->width, y * game->floor->height);
			draw_static_img(game, x, y);
			set_dynamic_items(game, x, y);
			if (game->map->grid[y][x] == '0' && y % 3 == 0 && x % 3 == 0)
				set_enemy(game->enemies_head, x, y);
		}
	}
}
