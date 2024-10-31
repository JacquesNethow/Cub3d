/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:09:37 by allan             #+#    #+#             */
/*   Updated: 2023/07/03 23:09:38 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_double_pointer(void **ptr)
{
	int	index;

	index = 0;
	while (ptr[index])
	{
		free(ptr[index]);
		ptr[index] = NULL;
		index++;
	}
	free(ptr);
	ptr = NULL;
}
