/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_space_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:19:54 by allan             #+#    #+#             */
/*   Updated: 2023/07/19 21:49:51 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_down(char **map, int i, int j)
{
	int	line_after;
	int	line_current;

	line_after = 0;
	line_current = ft_strlen(map[i]);
	if (map[i + 1])
		line_after = ft_strlen(map[i + 1]);
	if (j + 1 < line_current && j + 1 < line_after && i + 1 < ft_count_str(map))
	{
		if (!ft_strchr("1 ", map[i][j + 1]))
			return (FAILURE);
		if (!ft_strchr("1 ", map[i + 1][j + 1])
			|| !ft_strchr("1 ", map[i + 1][j]))
			return (FAILURE);
	}
	return (0);
}

int	check_around(char **map, int i, int j)
{
	int	line_current;
	int	line_before;

	line_before = 0;
	line_current = ft_strlen(map[i]);
	if (i - 1 >= 0)
		line_before = ft_strlen(map[i - 1]);
	if (check_down(map, i, j) == FAILURE)
		return (FAILURE);
	if (j + 1 < line_current && j + 1 < line_before && i - 1 > 0)
	{
		if (!ft_strchr("1 ", map[i - 1][j]))
			return (FAILURE);
		if (!ft_strchr("1 ", map[i - 1][j + 1]))
			return (FAILURE);
	}
	if (j - 1 > 0 && i - 1 > 0 && !ft_strchr("1 ", map[i - 1][j - 1]))
		return (FAILURE);
	return (0);
}

int	check_space_empty(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (ft_strchr(map[i], ' '))
		{
			while (map[i][j])
			{
				if (map[i][j] == ' ')
					if (check_around(map, i, j) == FAILURE)
						return (FAILURE);
				j++;
			}
		}
		i++;
	}
	return (0);
}
