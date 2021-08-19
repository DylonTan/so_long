#include "so_long.h"

void	free_exit(t_exit *exit)
{
	if (exit->obj)
		free(exit->obj);
	free(exit);
}

void	free_player(t_player *player)
{
	if (player->left_obj)
		free(player->left_obj);
	if (player->right_obj)
		free(player->right_obj);
	free(player);
}

void	free_collectibles(t_collectible **collectibles_head)
{
	t_collectible	*current;
	t_collectible	*temp;

	if (!collectibles_head)
		return ;
	current = *collectibles_head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(collectibles_head);
}

void	free_map_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_enemies(t_enemy **enemies_head)
{
	t_enemy	*current;
	t_enemy	*temp;

	if (!enemies_head)
		return ;
	current = *enemies_head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(enemies_head);
}
