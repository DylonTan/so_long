#include "so_long.h"

void	render_moves(t_game *game)
{
	char	*str;
	char	*moves;

	moves = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", moves);
	mlx_put_image_to_window(game->mlx, game->win, game->moves_bg->img, 0, 0);
	mlx_string_put(game->mlx, game->win, 0, 10, 0x00FF0000, str);
	free(moves);
	free(str);
}

int	render_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->map->obj->img,
		game->offset_x, game->offset_y);
	render_moves(game);
	render_collectibles(game);
	render_enemies(game);
	if (game->frames >= 144)
		game->frames = -1;
	game->frames++;
	render_player(game);
	return (1);
}

void	update_offset(t_game *game)
{
	if (game->player->x > game->map->width / 2 && game->map->width * 64 > 1920)
		game->offset_x = (game->map->width * 64 - 1920) * -1;
	else
		game->offset_x = 0;
	if (game->player->y > game->map->height / 2
		&& game->map->height * 64 > 1080)
		game->offset_y = (game->map->height * 64 - 1080) * -1;
	else
		game->offset_y = 0;
}

int	main(int argc, char **argv)
{
	t_game		*game;
	char		*file_path;
	int			width;
	int			height;

	if (argc > 1)
	{
		file_path = argv[1];
		get_map_size(file_path, &width, &height);
		game = init_game(width, height);
		parse_map(game, file_path);
		render_map(game);
		render_moves(game);
		update_offset(game);
		mlx_hook(game->win, 2, 1L << 0, handle_key_input, game);
		mlx_hook(game->win, 17, 0L, close_game, game);
		mlx_loop_hook(game->mlx, render_frame, game);
		mlx_loop(game->mlx);
	}
	else
		printf("Error: Invalid number of arguments\n");
}
