/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:59:04 by allan             #+#    #+#             */
/*   Updated: 2023/07/09 17:08:43 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	draw_rect(t_img *img, t_rect rect, int color)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.height)
	{
		j = rect.x;
		while (j < rect.width)
			img_pix_put(img, j++, i, color);
		++i;
	}
}
