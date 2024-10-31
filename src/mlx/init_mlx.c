/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:52:24 by allan             #+#    #+#             */
/*   Updated: 2023/07/03 23:59:13 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx(t_cub *cub)
{
	cub->config->mlx->mlx_ptr = mlx_init();
	cub->config->mlx->win_ptr = mlx_new_window(cub->config->mlx->mlx_ptr,
			WIDTH, HEIGHT, "window");
	cub->config->mlx->img.mlx_img = mlx_new_image(cub->config->mlx->mlx_ptr,
			WIDTH, HEIGHT);
	cub->config->mlx->img.addr
		= mlx_get_data_addr(cub->config->mlx->img.mlx_img,
			&cub->config->mlx->img.bpp,
			&cub->config->mlx->img.line_len, &cub->config->mlx->img.endian);
}
