/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:51:55 by allan             #+#    #+#             */
/*   Updated: 2023/07/09 17:49:11 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render(t_cub *data)
{
	handle_move(data);
	if (data->config->mlx->win_ptr == NULL)
		return (1);
	draw_rect(&data->config->mlx->img,
		(t_rect){0, 0, WIDTH, HEIGHT}, data->config->map_data->floor);
	draw_rect(&data->config->mlx->img,
		(t_rect){0, HEIGHT / 2, WIDTH, HEIGHT},
		data->config->map_data->ceiling);
	dda(&data);
	mlx_put_image_to_window(data->config->mlx->mlx_ptr,
		data->config->mlx->win_ptr, data->config->mlx->img.mlx_img, 0, 0);
	return (0);
}
