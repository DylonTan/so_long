#include "so_long.h"

t_collectible	**init_collectibles_head(void)
{
	t_collectible	**head;

	head = (t_collectible **) malloc(sizeof(t_collectible *));
	*head = NULL;
	return (head);
}
