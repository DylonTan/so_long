#include "so_long.h"

void	error_invalid_map(int fd)
{
	printf("Error\n");
	close(fd);
}
