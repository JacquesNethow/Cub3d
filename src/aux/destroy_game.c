/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:18:55 by jramondo          #+#    #+#             */
/*   Updated: 2023/07/12 22:40:51 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_player(t_play *player)
{
	if (player == NULL)
		return ;
	delete_vector(&player->position);
	delete_vector(&player->position_in_map);
	delete_vector(&player->direction);
	delete_vector(&player->field_of_vision);
	free (player);
}

void	destroy_image(t_cub *cub)
{
	if (cub->config->mlx->img.mlx_img)
		mlx_destroy_image(cub->config->mlx->mlx_ptr,
			cub->config->mlx->img.mlx_img);
}

void	destroy_texture(t_cub *cub)
{
	if (cub->config->map_data->no.mlx_img)
		mlx_destroy_image (cub->config->mlx->mlx_ptr,
			cub->config->map_data->no.mlx_img);
	if (cub->config->map_data->so.mlx_img)
		mlx_destroy_image (cub->config->mlx->mlx_ptr,
			cub->config->map_data->so.mlx_img);
	if (cub->config->map_data->we.mlx_img)
		mlx_destroy_image (cub->config->mlx->mlx_ptr,
			cub->config->map_data->we.mlx_img);
	if (cub->config->map_data->ea.mlx_img)
		mlx_destroy_image (cub->config->mlx->mlx_ptr,
			cub->config->map_data->ea.mlx_img);
}

void	destroy_map(t_map *map)
{
	if (map == NULL)
		return ;
	ft_matrix_strdel(map->map);
	free(map);
	map = NULL;
}
