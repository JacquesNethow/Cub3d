/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:43:25 by allan             #+#    #+#             */
/*   Updated: 2023/07/12 22:42:43 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	delete_config(t_config **config)
{
	(*config)->map_data = NULL;
	(*config)->mlx = NULL;
	free((*config));
	(*config) = NULL;
}
