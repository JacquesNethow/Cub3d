/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:28:58 by allan             #+#    #+#             */
/*   Updated: 2023/07/17 23:07:18 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_confirm_data_file(int *data_file, char *line_config)
{
	if (!ft_strncmp(line_config, "F", 1))
		data_file[F] = 1;
	if (!ft_strncmp(line_config, "C", 1))
		data_file[C] = 1;
	if (!ft_strncmp(line_config, "NO", 2))
		data_file[NO] = 1;
	if (!ft_strncmp(line_config, "SO", 2))
		data_file[SO] = 1;
	if (!ft_strncmp(line_config, "WE", 2))
		data_file[WE] = 1;
	if (!ft_strncmp(line_config, "EA", 2))
		data_file[EA] = 1;
}

int	check_string_texture(char **str)
{
	return (ft_count_str(str) >= 2
		&& ft_strncmp(str[0], "F", ft_strlen(str[0]))
		&& ft_strncmp(str[0], "C", ft_strlen(str[0])));
}

int	check_string_color(char **str)
{
	return (ft_count_str(str) >= 2
		&& (!ft_strncmp(str[0], "F", ft_strlen(str[0]))
			|| !ft_strncmp(str[0], "C", ft_strlen(str[0]))));
}

int	ft_check_color_and_texture(char *file, int *data_file)
{
	char	**line_config;
	int		fail;

	fail = 1;
	line_config = ft_split(file, ' ');
	ft_confirm_data_file(data_file, line_config[0]);
	if (check_string_texture(line_config))
	{
		if (ft_check_ext(line_config[1], "xpm") == -1
			|| ft_check_if_file_exist(line_config[1]) == -1)
			fail = -1;
	}
	else if (check_string_color(line_config))
	{
		if (ft_check_rgb(line_config[1]) == -1)
			fail = -1;
	}
	else
	{
		printf("Configuração errada\n");
		fail = -1;
	}
	free_double_pointer((void **)line_config);
	return (fail);
}

void	ft_check_config_file(char **file)
{
	int		index;
	int		*data_file;

	index = 0;
	data_file = ft_calloc(sizeof(int), 6);
	while (index < 6)
	{
		if (ft_check_color_and_texture(file[index], data_file) == -1)
		{
			free(data_file);
			free_double_pointer((void **) file);
			exit(FAILURE);
		}
		index++;
	}
	if (ft_check_all_data_file(data_file) == -1)
	{
		free(data_file);
		free_double_pointer((void **)file);
		exit(FAILURE);
	}
	free(data_file);
}
