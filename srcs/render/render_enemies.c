#include "so_long.h"

void	move_enemy(t_game *game, t_enemy *enemy)
{
	if (game->frames == 0)
	{
		if (game->map->grid[enemy->y - 1][enemy->x] == '0'
			&& !get_enemy(game->enemies_head, enemy->x, enemy->y - 1))
			enemy->y--;
		else if (game->map->grid[enemy->y][enemy->x + 1] == '0'
			&& !get_enemy(game->enemies_head, enemy->x + 1, enemy->y))
		{
			enemy->direction = 1;
			enemy->x++;
		}
		else if (game->map->grid[enemy->y + 1][enemy->x] == '0'
			&& !get_enemy(game->enemies_head, enemy->x, enemy->y + 1))
			enemy->y++;
		else if (game->map->grid[enemy->y][enemy->x - 1] == '0'
			&& !get_enemy(game->enemies_head, enemy->x - 1, enemy->y))
		{
			enemy->direction = -1;
			enemy->x--;
		}
	}
}

void	render_enemies(t_game *game)
{
	t_enemy	*head;

	head = *(game->enemies_head);
	while (head)
	{
		draw_on_img(game->map->obj, game->floor,
			head->x * game->floor->width, head->y * game->floor->height);
		move_enemy(game, head);
		if (head->direction == -1)
			draw_on_img(game->map->obj, game->enemy_left,
				head->x * game->enemy_left->width,
				head->y * game->enemy_left->height);
		else
			draw_on_img(game->map->obj, game->enemy_right,
				head->x * game->enemy_right->width,
				head->y * game->enemy_right->height);
		head = head->next;
	}
}
