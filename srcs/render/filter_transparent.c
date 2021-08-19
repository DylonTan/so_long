#include "so_long.h"

void	free_transparent(t_game *game, t_obj *obj, t_obj **temp)
{
	mlx_destroy_image(game->mlx, obj->img);
	obj->img = (*temp)->img;
	obj->addr = (*temp)->addr;
	free(*temp);
}

void	filter_transparent(t_game *game, t_obj *obj)
{
	t_obj	*temp;
	int		x;
	int		y;
	int		color;

	temp = init_obj();
	temp->img = mlx_new_image(game->mlx, obj->width, obj->height);
	temp->addr = mlx_get_data_addr(temp->img, &(temp->bits_per_pixel),
			&(temp->line_length), &(temp->endian));
	y = 0;
	while (y < obj->height)
	{
		x = 0;
		while (x < obj->width)
		{
			color = get_pixel_color(obj, x, y);
			if (color == 0)
				color = get_pixel_color(game->floor, x, y);
			set_pixel_color(temp, x, y, color);
			x++;
		}
		y++;
	}
	free_transparent(game, obj, &temp);
}
