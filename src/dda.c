/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:45:03 by allan             #+#    #+#             */
/*   Updated: 2023/07/19 21:26:11 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_dda(t_cub *data, t_dda *dda, double pixel)
{
	ft_bzero(dda, sizeof(t_dda));
	dda->multiplier = 2 * (pixel / WIDTH) - 1;
	dda->camera_pixel = mult_stack(data->play->field_of_vision,
			dda->multiplier);
	dda->ray_dir = sum_stack(data->play->direction, &dda->camera_pixel);
	dda->delta_dist.x = ft_abs_double(1 / dda->ray_dir.x);
	dda->delta_dist.y = ft_abs_double(1 / dda->ray_dir.y);
	dda->wall_map_pos = *(data->play->position_in_map);
}

static void	calculate_dist_to_side(t_cub *data, t_dda *dda)
{
	if (dda->ray_dir.x < 0)
	{
		dda->dist_to_side.x = (data->play->position->x
				- data->play->position_in_map->x) * dda->delta_dist.x;
		dda->step.x = -1;
	}
	else
	{
		dda->dist_to_side.x = (data->play->position_in_map->x
				+ 1 - data->play->position->x) * dda->delta_dist.x;
		dda->step.x = 1;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->dist_to_side.y = (data->play->position->y
				- data->play->position_in_map->y) * dda->delta_dist.y;
		dda->step.y = -1;
	}
	else
	{
		dda->dist_to_side.y = (data->play->position_in_map->y
				+ 1 - data->play->position->y) * dda->delta_dist.y;
		dda->step.y = 1;
	}
	dda->line_size = dda->dist_to_side;
}

static void	calculate_dist_perpen(t_cub *data, t_dda *dda)
{
	if (dda->hit_side == 0)
		dda->perpendicular_dist = ft_abs_double(dda->wall_map_pos.x
				- data->play->position->x
				+ ((1 - dda->step.x) / 2)) / dda->ray_dir.x;
	else
		dda->perpendicular_dist = ft_abs_double(dda->wall_map_pos.y
				- data->play->position->y
				+ ((1 - dda->step.y) / 2)) / dda->ray_dir.y;
}

static void	calculate_dist(t_cub *data, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->line_size.x < dda->line_size.y)
		{
			dda->wall_map_pos.x += dda->step.x;
			dda->line_size.x += dda->delta_dist.x;
			dda->hit_side = 0;
		}
		else
		{
			dda->wall_map_pos.y += dda->step.y;
			dda->line_size.y += dda->delta_dist.y;
			dda->hit_side = 1;
		}
		if (data->config->map_data->map[(int)dda->wall_map_pos.y]
			[(int)dda->wall_map_pos.x] == '1')
			dda->hit = 1;
	}
	calculate_dist_perpen(data, dda);
}

void	dda(t_cub **data)
{
	double	pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		init_dda((*data), (*data)->dda, pixel);
		calculate_dist_to_side((*data), (*data)->dda);
		calculate_dist((*data), (*data)->dda);
		create_line((*data)->dda, pixel);
		choice_texture((*data)->dda, (*data));
		draw_line((*data), (*data)->dda, (*data)->dda->texture,
			(*data)->dda->line);
		pixel += 1;
	}
}
