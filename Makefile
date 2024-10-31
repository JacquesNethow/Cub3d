NAME 	= cub3D

CC 		= cc

CFLAGS 	=  -Wall -Wextra -Werror

MLX_FLAGS = -lbsd -lmlx -lXext -lX11 -lm -lz

LIBFT 	= libs/libft/libft.a

SRC		=	src/main.c									\
			src/dda.c									\
			src/dda_aux.c								\
			src/struct/create_config.c					\
			src/struct/create_cub.c						\
			src/struct/delete_config.c					\
			src/struct/delete_cub.c						\
			src/mlx/close_game.c						\
			src/mlx/handle_key_aux.c					\
			src/mlx/handle_key.c						\
			src/mlx/init_mlx.c							\
			src/mlx/render.c							\
			src/load/config.c							\
			src/load/data.c								\
			src/load/map.c								\
			src/load/play.c								\
			src/check/args.c							\
			src/check/map_space_empty.c					\
			src/check/config.c							\
			src/check/config_aux.c						\
			src/check/map.c								\
			src/check/map_aux.c							\
			src/aux/destroy_game.c						\
			src/aux/free_double_point.c					\
			src/aux/handle_file.c						\
			libs/draw/src/draw_line.c					\
			libs/draw/src/draw_rect.c					\
			libs/draw/src/img_pix_put.c					\
			libs/vector/src/create_vector.c				\
			libs/vector/src/delete_vector.c				\
			libs/vector/src/vector_method.c				\
			libs/vector/src/vector_operations_stack.c	\
			libs/vector/src/vector_operations.c


OBJS	=	${SRC:%.c=%.o}

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME): 		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT)
				
$(LIBFT):
				make -C ./libs/libft

clean:
				rm -f $(OBJS) 
				make clean -C ./libs/libft

fclean:			clean
				rm -f $(NAME) 
				make fclean -C ./libs/libft

re:				fclean all

.PHONY: all clean fclean re