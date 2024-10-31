/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:42:42 by allan             #+#    #+#             */
/*   Updated: 2023/07/09 14:34:07 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_cub	*create_cub(void)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	cub->play = ft_calloc(sizeof(t_play), 1);
	cub->dda = ft_calloc(sizeof(t_dda), 1);
	cub->config = create_config();
	return (cub);
}
