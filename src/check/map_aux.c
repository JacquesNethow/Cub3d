/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:27:07 by allan             #+#    #+#             */
/*   Updated: 2023/07/19 21:55:28 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_wall_max(char **map)
{
	int	line[2];
	int	count;
	int	i;

	i = 0;
	while (map[++i])
	{
		count = 0;
		line[0] = ft_strlen(map[i]);
		if (map[i + 1])
			line[1] = ft_strlen(map[i + 1]);
		if (line[1] > line[0])
		{
			while (map[i + 1][line[0] + count])
				if (!ft_strchr("1", map[i + 1][line[0] + count++]))
					return (FAILURE);
		}
		else if (line[1] < line[0])
		{
			while (map[i][line[1] + count])
				if (!ft_strchr("1", map[i][line[1] + count++]))
					return (FAILURE);
		}
	}
	return (0);
}

static int	check_line(char *line)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while (line[index] != '\0')
	{
		if (line[index] == 'N' || line[index] == 'S'
			|| line[index] == 'E' || line[index] == 'W')
			result++;
		index++;
	}
	return (result);
}

static int	check_walls_aux(char **map)
{
	int	index;
	int	len;

	index = 0;
	while (map[index])
	{
		len = ft_strlen(map[index]);
		if (ft_strchr("NSEW0", map[index][0])
			|| ft_strchr("NSEW0", map[index][len - 1]))
			return (1);
		index++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	x;
	int	len;
	int	size_map;

	x = 0;
	size_map = ft_count_str(map);
	if (check_walls_aux(map))
		return (1);
	len = ft_strlen(map[0]);
	while (x < len)
	{
		if (ft_strchr("NSEW0", map[0][x]))
			return (1);
		x++;
	}
	len = ft_strlen(map[size_map - 1]);
	x = -1;
	while (++x < len)
		if (ft_strchr("NSEW0", map[size_map - 1][x]))
			return (1);
	if (check_space_empty(map) == FAILURE || check_wall_max(map) == FAILURE)
		return (FAILURE);
	return (0);
}

int	check_player(char **map)
{
	int	index;
	int	qt_persons;

	index = 0;
	qt_persons = 0;
	while (map[index] != NULL)
	{
		qt_persons += check_line(map[index]);
		index++;
	}
	if (qt_persons != 1)
		return (1);
	return (0);
}
