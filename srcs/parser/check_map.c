#include "so_long.h"

int	is_valid_map_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map_line(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	len = 0;
	while (line[len])
	{
		if (line[len] != '1' && line[len] != '0' && line[len] != 'P'
			&& line[len] != 'C' && line[len] != 'E')
			return (0);
		len++;
	}
	return (1);
}

int	is_valid_map_items(char **grid)
{
	int	x;
	int	y;
	int	player;
	int	collectibles;
	int	exit;

	x = -1;
	y = -1;
	player = 0;
	collectibles = 0;
	exit = 0;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == 'P')
				player++;
			else if (grid[y][x] == 'C')
				collectibles++;
			else if (grid[y][x] == 'E')
				exit++;
		}
	}
	return (player != 0 && collectibles != 0 && exit != 0);
}
