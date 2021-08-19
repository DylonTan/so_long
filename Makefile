NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

INCS = includes

SRCS = srcs/so_long.c \
		srcs/structs/game.c srcs/structs/map.c srcs/structs/exit.c srcs/structs/obj.c srcs/structs/player.c srcs/structs/enemy.c srcs/structs/enemies_head.c srcs/structs/collectibles_head.c \
		srcs/input/handle_key_input.c srcs/input/handle_collect_collectible.c srcs/input/handle_visit_exit.c srcs/input/handle_collide_enemy.c \
		srcs/render/draw.c srcs/render/filter_transparent.c srcs/render/render_map.c srcs/render/render_player.c srcs/render/render_enemies.c srcs/render/render_collectibles.c\
		srcs/parser/parse_map.c srcs/parser/get_map_line.c srcs/parser/get_map_size.c srcs/parser/check_map.c \
		srcs/utils/str_utils.c srcs/utils/list_utils.c \
		srcs/error/error_invalid_map.c \
		srcs/close/close_game.c srcs/close/free_game.c srcs/close/free_game_items.c
OBJS = $(SRCS:.c=.o)

MLX = mlx_Linux
MLX_DIR = mlx_linux

LIBFT = libft

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) -L$(LIBFT) -lft -L$(MLX_DIR) -l$(MLX) -I$(INCS) -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(INCS) -I$(MLX_DIR) -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
