/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:35:44 by allan             #+#    #+#             */
/*   Updated: 2023/07/19 21:28:25 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_texture(t_mlx *mlx, t_img *img, char *path)
{
	int	size;

	size = TEXTURES_SIZE;
	img->mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &size, &size);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
}

static void	load_texture(char **data_texture, t_cub **cub)
{
	if (!ft_strncmp(data_texture[0], "NO", ft_strlen(data_texture[0])))
		get_texture((*cub)->config->mlx,
			&(*cub)->config->map_data->no, data_texture[1]);
	if (!ft_strncmp(data_texture[0], "SO", ft_strlen(data_texture[0])))
		get_texture((*cub)->config->mlx,
			&(*cub)->config->map_data->so, data_texture[1]);
	if (!ft_strncmp(data_texture[0], "WE", ft_strlen(data_texture[0])))
		get_texture((*cub)->config->mlx,
			&(*cub)->config->map_data->we, data_texture[1]);
	if (!ft_strncmp(data_texture[0], "EA", ft_strlen(data_texture[0])))
		get_texture((*cub)->config->mlx,
			&(*cub)->config->map_data->ea, data_texture[1]);
}

static void	get_color(int *color, char *rgb_color)
{
	char	**rgb;
	int		index;

	index = 0;
	rgb = ft_split(rgb_color, ',');
	while (rgb[index])
	{
		*color = *color | ft_atoi(rgb[index]) << 8 * index;
		index++;
	}
	free_double_pointer((void **)rgb);
}

static void	load_color(char **data_color, t_cub **cub)
{
	if (!ft_strncmp(data_color[0], "F", ft_strlen(data_color[0])))
		get_color(&(*cub)->config->map_data->floor, data_color[1]);
	if (!ft_strncmp(data_color[0], "C", ft_strlen(data_color[0])))
		get_color(&(*cub)->config->map_data->ceiling, data_color[1]);
}

void	load_config(t_cub **cub, char **file)
{
	int		index;
	char	**line_config;

	index = 0;
	while (index < 6)
	{
		line_config = ft_split(file[index], ' ');
		if (ft_strncmp(line_config[0], "F", ft_strlen(line_config[0]))
			&& ft_strncmp(line_config[0], "C", ft_strlen(line_config[0])))
			load_texture(line_config, cub);
		else if (!ft_strncmp(line_config[0], "F", ft_strlen(line_config[0]))
			|| !ft_strncmp(line_config[0], "C", ft_strlen(line_config[0])))
			load_color(line_config, cub);
		free_double_pointer((void **)line_config);
		index++;
	}
}
