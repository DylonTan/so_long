#include "so_long.h"
#include <stdio.h>
int	get_pixel_color(t_obj *obj, int x, int y)
{
	char	*dst;
	int		offset_x;
	int		offset_y;

	offset_x = x * (obj->bits_per_pixel / 8);
	offset_y = y * (obj->line_length);
	dst = obj->addr + offset_x + offset_y;
	return (*(int *)dst);
}

void	set_pixel_color(t_obj *obj, int x, int y, int color)
{
	char	*dst;
	int		offset_x;
	int		offset_y;

	offset_x = x * (obj->bits_per_pixel / 8);
	offset_y = y * (obj->line_length);
	dst = obj->addr + offset_x + offset_y;
	*(unsigned int *)dst = color;
}

void	draw_on_img(t_obj *img_to, t_obj *img_from, int x, int y)
{
	int	img_from_x;
	int	img_from_y;
	int	img_to_x;
	int	img_to_y;
	int	color;

	img_from_y = 0;
	img_to_x = x;
	img_to_y = y;
	while (img_from_y < img_from->height)
	{
		img_from_x = 0;
		while (img_from_x < img_from->width)
		{
			img_to_x = x + img_from_x;
			img_to_y = y + img_from_y;
			color = get_pixel_color(img_from, img_from_x, img_from_y);
			set_pixel_color(img_to, img_to_x, img_to_y, color);
			img_from_x++;
		}
		img_from_y++;
	}
}
