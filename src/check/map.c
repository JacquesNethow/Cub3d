/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:13:38 by allan             #+#    #+#             */
/*   Updated: 2023/07/18 01:36:19 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_spaces_aux(char **map, int i)
{
	int	index;

	index = 0;
	while (map[i][index])
	{
		if (map[i][index] == ' ')
		{
			if (map[i][index + 1] && ft_strchr("NSEW0", map[i][index + 1]))
				return (1);
			if ((index > 0) && ft_strchr("NSEW0", map[i][index - 1]))
				return (1);
			if (map[i + 1] != NULL && map[i + 1][index]
				&& ft_strchr("NSEW0", map[i + 1][index]))
				return (1);
			if ((i > 0) && ft_strchr("NSEW0", map[i - 1][index]))
				return (1);
		}
		index++;
	}
	return (0);
}

static int	check_spaces(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_spaces_aux(map, i))
			return (1);
		i++;
	}
	return (0);
}

static int	check_characters_map(char **map)
{
	int		index;
	int		count;
	char	temp;

	index = 0;
	while (map[index] != NULL)
	{
		count = 0;
		while (map[index][count])
		{
			temp = map[index][count];
			if (temp == ' ' || temp == '1' || temp == '0'
				|| temp == 'N' || temp == 'E' || temp == 'W'
				|| temp == '	' || temp == 'S')
				count++;
			else
				return (1);
		}
		index++;
	}
	return (0);
}

int	check_map(char **map)
{
	if (check_walls(map))
	{
		printf("Error!\nMap walls are wrong\n");
		return (FAILURE);
	}
	if (check_spaces(map))
	{
		printf("Error!\nThe walls of the map are not correctly closed\n");
		return (FAILURE);
	}
	if (check_player(map))
	{
		printf("Error!\nThe player is wrong\n");
		return (FAILURE);
	}
	if (check_characters_map(map))
	{
		printf("Error!\nWrong character in map\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
