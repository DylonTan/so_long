#include "so_long.h"

t_obj	*init_obj(void)
{
	t_obj	*obj;

	obj = (t_obj *) malloc(sizeof(t_obj));
	obj->img = NULL;
	obj->addr = NULL;
	obj->bits_per_pixel = 0;
	obj->line_length = 0;
	obj->endian = 0;
	obj->width = 0;
	obj->height = 0;
	return (obj);
}
