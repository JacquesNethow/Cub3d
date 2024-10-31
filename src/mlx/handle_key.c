/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:53:28 by allan             #+#    #+#             */
/*   Updated: 2023/07/20 03:23:14 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall(char **map, double y, double x)
{
	if (map[(int)floor(y)][(int)floor(x)] == '1')
		return (0);
	return (1);
}

int	handle_move(t_cub *data)
{
	if (data->key == ESC)
		close_game(data);
	if (data->mov
		&& (data->key == ARROW_LEFT || data->key == ARROW_RIGHT))
		rotate_play(data);
	if (data->mov
		&& (data->key == 'W' || data->key == 'w'
			|| data->key == 'S' || data->key == 's'))
		move_top_down(data);
	if (data->mov
		&& (data->key == 'A' || data->key == 'a'
			|| data->key == 'D' || data->key == 'd'))
		move_left_right(data);
	data->play->position_in_map->y = (int)(data->play->position->y);
	data->play->position_in_map->x = (int)(data->play->position->x);
	return (0);
}

int	handle_keypress(int keysym, t_cub *data)
{
	data->mov = 1;
	data->key = keysym;
	return (0);
}

int	handle_keydown(int keysym, t_cub *data)
{
	data->mov = 0;
	data->key = keysym;
	return (0);
}
