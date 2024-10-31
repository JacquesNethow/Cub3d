/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:25:36 by allan             #+#    #+#             */
/*   Updated: 2023/07/18 01:06:55 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_ext(char *line, char *ext)
{
	char	**file_name_split;
	size_t	amount_string;
	char	*extension;

	file_name_split = ft_split(line, '.');
	amount_string = ft_count_str(file_name_split);
	extension = file_name_split[amount_string - 1];
	if (ft_strncmp(extension, ext, ft_strlen(ext))
		|| ft_strncmp(extension, ext, ft_strlen(extension)))
	{
		free_double_pointer((void **)file_name_split);
		printf(ERROR_EXTENSION_FILE);
		return (1);
	}
	free_double_pointer((void **)file_name_split);
	return (0);
}

int	ft_check_int(char *str)
{
	char	*cmp;

	cmp = ft_itoa(ft_atoi(str));
	if (ft_strncmp(str, cmp, ft_strlen(str)))
	{
		free(cmp);
		return (0);
	}
	free(cmp);
	return (1);
}

int	ft_check_if_file_exist(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == FAILURE)
	{
		perror(FILE_NOT_FOUND);
		return (FAILURE);
	}
	close(fd);
	return (0);
}

int	ft_check_rgb(char *rgb)
{
	char	**colors;
	int		index;
	int		color;

	colors = ft_split(rgb, ',');
	index = 0;
	while (colors[index])
	{
		if (!ft_check_int(colors[index]))
		{
			free_double_pointer((void **)colors);
			perror(CONFIG_DATA_INVALID);
			return (FAILURE);
		}
		color = ft_atoi(colors[index]);
		if (color < 0 || color > 255)
		{
			free_double_pointer((void **)colors);
			perror(CONFIG_DATA_INVALID);
			return (FAILURE);
		}
		index++;
	}
	free_double_pointer((void **)colors);
	return (SUCCESS);
}

int	ft_check_all_data_file(int *data)
{
	int	i;

	i = 0;
	while (i < 6)
		if (!data[i++])
			return (FAILURE);
	return (SUCCESS);
}
