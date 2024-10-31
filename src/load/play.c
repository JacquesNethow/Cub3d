/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:40:09 by allan             #+#    #+#             */
/*   Updated: 2023/07/19 21:34:15 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_direction(t_cub **cub, char direction)
{
	if (direction == 'N')
	{
		(*cub)->play->direction = create_vector(0.0, -1.0);
		(*cub)->play->field_of_vision = create_vector(-0.60, 0.0);
		(*cub)->rotate = -1;
	}
	if (direction == 'S')
	{
		(*cub)->play->direction = create_vector(0.0, 1.0);
		(*cub)->play->field_of_vision = create_vector(0.60, 0.0);
		(*cub)->rotate = -1;
	}
	if (direction == 'W')
	{
		(*cub)->play->direction = create_vector(-1.0, 0.0);
		(*cub)->play->field_of_vision = create_vector(0.0, -0.60);
		(*cub)->rotate = 1;
	}
	if (direction == 'E')
	{
		(*cub)->play->direction = create_vector(1.0, 0.0);
		(*cub)->play->field_of_vision = create_vector(0.0, 0.60);
		(*cub)->rotate = 1;
	}
}

void	load_play(t_cub **cub)
{
	double	x;
	double	y;
	int		meet;

	meet = 0;
	y = 0;
	while ((*cub)->config->map_data->map[(int)y] && !meet)
	{
		x = 0;
		while ((*cub)->config->map_data->map[(int)y][(int)x] && !meet)
		{
			if (ft_strchr("NSEW",
					(*cub)->config->map_data->map[(int)y][(int)x]))
			{
				(*cub)->play->position = create_vector(x + 0.5, y + 0.5);
				(*cub)->play->position_in_map = create_vector(x, y);
				load_direction(cub,
					(*cub)->config->map_data->map[(int)y][(int)x]);
				meet = 1;
			}
			x++;
		}
		y++;
	}
}
