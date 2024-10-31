/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:05:08 by allan             #+#    #+#             */
/*   Updated: 2023/07/19 21:38:39 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_line(t_dda *dda, double pixel)
{
	t_line	line;

	dda->wall_height = (int)(HEIGHT / ft_abs_double(dda->perpendicular_dist));
	line.x_f = pixel;
	line.x_o = pixel;
	line.y_f = floor(HEIGHT / 2 + dda->wall_height / 2);
	if (line.y_f > HEIGHT)
		line.y_f = HEIGHT;
	line.y_o = floor(HEIGHT / 2 - dda->wall_height / 2);
	if (line.y_o < 0)
		line.y_o = 0;
	line.proportionality_constant = WIDTH / HEIGHT;
	line.step = 1.0;
	dda->line = line;
}

static void	choice_texture_side(t_dda *dda, t_cub *cub)
{
	if (cub->rotate == -1)
	{
		if (dda->step.x > 0 && dda->step.y > 0)
			dda->texture = &cub->config->map_data->we;
		if (dda->step.x < 0 && dda->step.y > 0)
			dda->texture = &cub->config->map_data->ea;
		if (dda->step.x > 0 && dda->step.y < 0)
			dda->texture = &cub->config->map_data->we;
		if (dda->step.x < 0 && dda->step.y < 0)
			dda->texture = &cub->config->map_data->ea;
	}
	else
	{
		if (dda->step.x > 0 && dda->step.y > 0)
			dda->texture = &cub->config->map_data->ea;
		if (dda->step.x < 0 && dda->step.y > 0)
			dda->texture = &cub->config->map_data->we;
		if (dda->step.x > 0 && dda->step.y < 0)
			dda->texture = &cub->config->map_data->ea;
		if (dda->step.x < 0 && dda->step.y < 0)
			dda->texture = &cub->config->map_data->we;
	}
}

void	choice_texture(t_dda *dda, t_cub *cub)
{
	if (dda->hit_side)
	{
		if (dda->step.x > 0 && dda->step.y > 0)
			dda->texture = &cub->config->map_data->so;
		if (dda->step.x < 0 && dda->step.y > 0)
			dda->texture = &cub->config->map_data->so;
		if (dda->step.x > 0 && dda->step.y < 0)
			dda->texture = &cub->config->map_data->no;
		if (dda->step.x < 0 && dda->step.y < 0)
			dda->texture = &cub->config->map_data->no;
	}
	else
		choice_texture_side(dda, cub);
}
