/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:59:02 by allan             #+#    #+#             */
/*   Updated: 2023/07/11 21:50:48 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_pixel_texture(t_img *texture, size_t x, size_t y)
{
	size_t	index;
	int		color;

	if (!texture)
		return (0);
	index = y * texture->line_len + x * texture->bpp / 8;
	color = (*(int *)(texture->addr + index));
	return (color);
}

t_line	swap_line(t_line	line)
{
	if (line.x_o > line.x_f)
		ft_swap(&line.x_o, &line.x_o, sizeof(double));
	if (line.y_o > line.y_f)
		ft_swap(&line.y_o, &line.y_f, sizeof(double));
	return (line);
}

int	calcule_pos_texture_x(t_cub *cub, t_dda *dda, t_img *texture)
{
	double	wall_x;

	if (dda->hit_side == 0)
		wall_x = cub->play->position->y
			+ (dda->perpendicular_dist * dda->ray_dir.y) * cub->dda->step.x;
	else
		wall_x = cub->play->position->x
			+ (dda->perpendicular_dist * dda->ray_dir.x) * cub->dda->step.y;
	wall_x -= floor(wall_x);
	return ((int)(wall_x * texture->bpp));
}

void	draw_line(t_cub *cub, t_dda *dda, t_img *texture, t_line line)
{
	int		pos_texture_x;
	int		pos_texture_y;
	double	pos_texture;
	double	step;

	line = swap_line(line);
	pos_texture_x = calcule_pos_texture_x(cub, dda, texture);
	step = 1.0 * (texture->bpp / ft_abs_double(dda->wall_height));
	pos_texture = ft_abs_double((line.y_o - (HEIGHT / 2)
				+ (dda->wall_height / 2))) * step;
	while (line.x_o < line.x_f || line.y_o < line.y_f)
	{
		pos_texture_y = (int)pos_texture & (31);
		img_pix_put(&cub->config->mlx->img, line.x_o, line.y_o,
			get_pixel_texture(texture, pos_texture_x, pos_texture_y));
		if (line.x_o < line.x_f)
			line.x_o += line.step;
		if (line.y_o < line.y_f)
			line.y_o += line.step;
		pos_texture += step;
	}
}
