#include "so_long.h"

t_collectible	*get_collectible(t_collectible **collectibles_head,
		int x, int y)
{
	t_collectible	*cur;

	cur = *collectibles_head;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	set_collectible(t_collectible **collectibles_head, int x, int y)
{
	t_collectible	*collectible;

	if (!collectibles_head)
		return ;
	collectible = (t_collectible *) malloc(sizeof(t_collectible));
	collectible->x = x;
	collectible->y = y;
	collectible->is_collected = 0;
	collectible->next = *collectibles_head;
	*collectibles_head = collectible;
}

t_enemy	*get_enemy(t_enemy **enemies_head, int x, int y)
{
	t_enemy	*cur;

	cur = *enemies_head;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	set_enemy(t_enemy **enemies_head, int x, int y)
{
	t_enemy	*enemy;

	if (!enemies_head)
		return ;
	enemy = (t_enemy *) malloc(sizeof(t_enemy));
	enemy->x = x;
	enemy->y = y;
	enemy->direction = -1;
	enemy->next = *enemies_head;
	*enemies_head = enemy;
}
