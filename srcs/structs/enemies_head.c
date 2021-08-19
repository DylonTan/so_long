#include "so_long.h"

t_enemy	**init_enemies_head(void)
{
	t_enemy	**head;

	head = (t_enemy **) malloc(sizeof(t_enemy *));
	*head = NULL;
	return (head);
}
