#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_obj {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_obj;

typedef struct s_collectible {
	int						x;
	int						y;
	int						is_collected;
	struct s_collectible	*next;
}				t_collectible;

typedef struct s_enemy {
	int				x;
	int				y;
	int				direction;
	struct s_enemy	*next;
}				t_enemy;

typedef struct s_player {
	t_obj	*left_obj;
	t_obj	*right_obj;
	int		x;
	int		y;
	int		direction;
}				t_player;

typedef struct s_exit {
	t_obj	*obj;
	int		x;
	int		y;
	int		is_visited;
}				t_exit;

typedef struct s_map {
	t_obj	*obj;
	int		width;
	int		height;
	char	**grid;
	int		collectibles_left;
}				t_map;

typedef struct s_game {
	void			*mlx;
	void			*win;
	struct s_obj	*collectible;
	struct s_obj	*floor;
	struct s_obj	*wall;
	struct s_obj	*enemy_left;
	struct s_obj	*enemy_right;
	struct s_obj	*moves_bg;
	struct s_exit	*exit;
	struct s_player	*player;
	struct s_map	*map;
	t_collectible	**collectibles_head;
	t_enemy			**enemies_head;
	int				frames;
	int				offset_x;
	int				offset_y;
	int				win_width;
	int				win_height;
	int				moves;
}				t_game;

// STRUCTS

t_game			*init_game(int width, int height);

t_obj			*init_obj(void);

t_map			*init_map(void);

t_exit			*init_exit(t_game *game);

t_player		*init_player(t_game *game);

t_obj			*init_enemy_right(t_game *game);

t_obj			*init_enemy_left(t_game *game);

t_collectible	*init_collectible(void);

t_collectible	**init_collectibles_head(void);

t_enemy			**init_enemies_head(void);

// INPUT

int				handle_key_input(int keycode, t_game *game);

void			handle_collect_collectible(t_game *game);

void			handle_visit_exit(t_game *game);

void			handle_collide_enemy(t_game *game);

// PARSER

char			*get_map_line(int fd);

void			get_map_size(char *file_path, int *width, int *height);

void			parse_map(t_game *game, char *file_path);

void			error_map(char **line, int fd);

int				is_valid_map_walls(char *line);

int				is_valid_map_line(char *line);

int				is_valid_map_items(char **grid);

int				is_valid_map_walls(char *line);

int				is_valid_map_line(char *line);

int				is_valid_map_items(char **grid);

// RENDER

int				get_pixel_color(t_obj *obj, int x, int y);

void			set_pixel_color(t_obj *obj, int x, int y, int color);

void			draw_on_img(t_obj *img_to, t_obj *img_from, int x, int y);

void			filter_transparent(t_game *game, t_obj *obj);

void			render_map(t_game *game);

void			render_player(t_game *game);

void			render_collectibles(t_game *game);

void			render_enemies(t_game *game);

void			render_moves(t_game *game);

// UTILS

void			ft_strdel(char **ptr);

char			*ft_strnew(size_t size);

void			set_collectible(t_collectible **collectibles_head,
					int x, int y);

t_collectible	*get_collectible(t_collectible **collectibles_head,
					int x, int y);

void			set_enemy(t_enemy **enemies_head, int x, int y);

t_enemy			*get_enemy(t_enemy **enemies_head, int x, int y);

// ERROR

void			error_invalid_map(int fd);

// CLOSE

int				close_game(t_game *game);

void			free_game(t_game *game);

void			free_exit(t_exit *exit);

void			free_player(t_player *player);

void			free_collectibles(t_collectible **collectibles_head);

void			free_map_grid(char **grid);

void			free_enemies(t_enemy **enemies_head);

#endif
