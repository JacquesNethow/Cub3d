/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:38:26 by allan             #+#    #+#             */
/*   Updated: 2023/07/03 23:39:58 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_map(t_cub **cub, char **map)
{
	int	index;
	int	amount_line;

	index = 0;
	amount_line = ft_count_str(map);
	(*cub)->config->map_data->map = ft_calloc(sizeof(char *), amount_line + 1);
	while (map[index])
	{
		(*cub)->config->map_data->map[index] = ft_strdup(map[index]);
		index++;
	}
}
