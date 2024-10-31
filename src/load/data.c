/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:37:52 by allan             #+#    #+#             */
/*   Updated: 2023/07/19 21:28:24 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_data(t_cub **cub, char **file)
{
	(*cub) = create_cub();
	init_mlx((*cub));
	load_config(cub, file);
	load_map(cub, &file[6]);
	load_play(cub);
	free_double_pointer((void **)file);
}
