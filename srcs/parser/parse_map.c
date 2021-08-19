#include "so_long.h"

void	init_map_grid(t_game *game)
{
	int	i;

	game->map->grid = (char **) malloc(sizeof(char *)
			* (game->map->height + 1));
	i = 0;
	while (i <= game->map->height)
	{
		game->map->grid[i] = NULL;
		i++;
	}
}

void	check_map_items(t_game *game, int fd)
{
	if (!is_valid_map_items(game->map->grid))
	{
		error_invalid_map(fd);
		close_game(game);
	}
}

void	parse_map(t_game *game, char *file_path)
{
	int		i;
	int		fd;
	char	*line;

	init_map_grid(game);
	fd = open(file_path, O_RDONLY);
	line = get_map_line(fd);
	if (!line)
		error_map(&line, fd);
	i = 0;
	while (line && i < game->map->height)
	{
		if (i == 0 || i == game->map->height - 1)
			if (!is_valid_map_walls(line))
				error_map(&line, fd);
		if (!is_valid_map_line(line))
			error_map(&line, fd);
		game->map->grid[i] = ft_strdup(line);
		free(line);
		line = get_map_line(fd);
		i++;
	}
	check_map_items(game, fd);
	game->map->grid[i] = NULL;
}
