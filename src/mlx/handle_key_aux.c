/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:01:34 by allan             #+#    #+#             */
/*   Updated: 2023/07/09 22:04:55 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_play(t_cub *data)
{
	if (data->key == ARROW_LEFT)
	{
		rotate(&data->play->direction, -0.005 * data->rotate);
		rotate(&data->play->field_of_vision, -0.005 * data->rotate);
	}
	if (data->key == ARROW_RIGHT)
	{
		rotate(&data->play->direction, 0.005 * data->rotate);
		rotate(&data->play->field_of_vision, 0.005 * data->rotate);
	}
}

void	move_top_down(t_cub *data)
{
	if ((data->key == 'W' || data->key == 'w')
		&& is_wall(data->config->map_data->map,
			data->play->position->y + 0.1 * data->play->direction->y,
			data->play->position->x + 0.1 * data->play->direction->x))
	{
		data->play->position->y += 0.025 * data->play->direction->y;
		data->play->position->x += 0.025 * data->play->direction->x;
	}
	if ((data->key == 'S' || data->key == 's')
		&& is_wall(data->config->map_data->map,
			data->play->position->y - 0.1 * data->play->direction->y,
			data->play->position->x - 0.1 * data->play->direction->x))
	{
		data->play->position->y -= 0.025 * data->play->direction->y;
		data->play->position->x -= 0.025 * data->play->direction->x;
	}
}

void	move_left_right(t_cub *data)
{
	if ((data->key == 'A' || data->key == 'a')
		&& is_wall(data->config->map_data->map,
			data->play->position->y - 0.1 * data->play->field_of_vision->y,
			data->play->position->x - 0.1 * data->play->field_of_vision->x))
	{
		data->play->position->y -= 0.025 * data->play->field_of_vision->y;
		data->play->position->x -= 0.025 * data->play->field_of_vision->x;
	}
	if ((data->key == 'D' || data->key == 'd')
		&& is_wall(data->config->map_data->map,
			data->play->position->y + 0.1 * data->play->field_of_vision->y,
			data->play->position->x + 0.1 * data->play->field_of_vision->x))
	{
		data->play->position->y += 0.025 * data->play->field_of_vision->y;
		data->play->position->x += 0.025 * data->play->field_of_vision->x;
	}
}
