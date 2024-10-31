/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:13:52 by jramondo          #+#    #+#             */
/*   Updated: 2023/07/12 22:50:15 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	destroy_game(t_cub *cub)
{
	if (cub == NULL)
		return (1);
	destroy_player(cub->play);
	destroy_image(cub);
	destroy_texture(cub);
	destroy_map(cub->config->map_data);
	if (cub->config->mlx->win_ptr)
		mlx_destroy_window(cub->config->mlx->mlx_ptr,
			cub->config->mlx->win_ptr);
	if (cub->config->mlx->mlx_ptr)
	{
		mlx_destroy_display(cub->config->mlx->mlx_ptr);
		free (cub->config->mlx->mlx_ptr);
		free (cub->config->mlx);
	}
	free(cub->dda);
	delete_config(&cub->config);
	delete_cub(&cub);
	exit (0);
	return (0);
}

int	close_game(t_cub *cub)
{
	mlx_loop_end(cub->config->mlx->mlx_ptr);
	destroy_game(cub);
	return (0);
}
