#include "so_long.h"

void	error_map(char **line, int fd)
{
	free(*line);
	error_invalid_map(fd);
	exit(0);
}

void	get_map_size(char *file_path, int *width, int *height)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = get_map_line(fd);
	if (!line)
		error_map(&line, fd);
	len = ft_strlen(line);
	*width = len;
	*height = 0;
	while (line)
	{
		len = ft_strlen(line);
		if (len < 0 || len != *width)
		{
			free(line);
			error_invalid_map(fd);
			exit(0);
		}
		(*height)++;
		free(line);
		line = get_map_line(fd);
	}
	close(fd);
}
