/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:47:20 by allan             #+#    #+#             */
/*   Updated: 2023/07/17 23:25:53 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include "../libs/vector/includes/vector.h"
# include "../libs/draw/includes/draw.h"
# include "./defines.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}t_mlx;

typedef struct s_map {
	char	**map;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	int		floor;
	int		ceiling;
}t_map;

typedef struct s_config{
	t_map	*map_data;
	t_mlx	*mlx;
}t_config;

typedef struct s_play{
	t_vector	*position;
	t_vector	*position_in_map;
	t_vector	*direction;
	t_vector	*field_of_vision;
}t_play;

typedef struct s_dda
{
	t_vector	delta_dist;
	t_vector	dist_to_side;
	t_vector	step;
	t_vector	line_size;
	t_vector	camera_pixel;
	t_vector	ray_dir;
	t_vector	wall_map_pos;
	t_img		*texture;
	int			hit;
	int			hit_side;
	int			wall_height;
	double		perpendicular_dist;
	t_line		line;
	double		multiplier;
}t_dda;

typedef struct s_cub{
	t_play		*play;
	t_config	*config;
	int			render;
	int			rotate;
	int			key;
	int			mov;
	t_dda		*dda;
}t_cub;

typedef struct s_valid_texture
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	c;
	int	f;
}t_valid_texture;

t_cub		*create_cub(void);
void		delete_cub(t_cub **cub);
t_config	*create_config(void);
void		delete_config(t_config **config);
void		dda(t_cub **data);
void		draw_line(t_cub *cub, t_dda *dda, t_img *texture, t_line line);
void		free_double_pointer(void **ptr);
void		load_play(t_cub **cub);
void		load_config(t_cub **cub, char **file);
void		load_data(t_cub **cub, char **file);
void		load_map(t_cub **cub, char **map);
int			ft_count_str(char **str);
void		init_mlx(t_cub *cub);
int			check_map(char **map);
int			check_walls(char **map);
int			check_player(char **map);
int			render(t_cub *data);
int			handle_keypress(int keysym, t_cub *data);
char		**ft_read_file(char *file_name, int amount_line_in_file);
int			ft_count_line_in_file(char *file_name);
int			ft_count_str(char **str);
int			ft_check_if_file_exist(char *file_name);
int			ft_check_rgb(char *rgb);
void		ft_check_config_file(char **file);
int			ft_check_args(int argc, char **argv);
int			ft_check_ext(char *line, char *ext);
int			ft_check_int(char *str);
int			handle_move(t_cub *data);
int			handle_keydown(int keysym, t_cub *data);
void		rotate_play(t_cub *data);
void		move_top_down(t_cub *data);
void		move_left_right(t_cub *data);
int			is_wall(char **map, double y, double x);
void		create_line(t_dda *dda, double pixel);
void		choice_texture(t_dda *dda, t_cub *cub);
int			destroy_game(t_cub *cub);
int			close_game(t_cub *cub);
void		destroy_player(t_play *player);
void		destroy_image(t_cub *cub);
void		destroy_texture(t_cub *cub);
void		destroy_map(t_map *map);
int			ft_check_all_data_file(int *data);
int			check_space_empty(char **map);
#endif