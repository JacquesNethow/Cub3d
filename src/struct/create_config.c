/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:42:05 by allan             #+#    #+#             */
/*   Updated: 2023/07/12 22:47:53 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_config	*create_config(void)
{
	t_config	*config;

	config = ft_calloc(sizeof(t_config), 1);
	config->map_data = ft_calloc(sizeof(t_map), 1);
	config->mlx = ft_calloc(sizeof(t_mlx), 1);
	return (config);
}
