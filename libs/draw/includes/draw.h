/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:59:26 by allan             #+#    #+#             */
/*   Updated: 2023/07/12 02:13:23 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <mlx.h>
# include "../../libft/libft.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;

typedef struct s_line
{
	double	x_o;
	double	y_o;
	double	x_f;
	double	y_f;
	double	proportionality_constant;
	double	step;
}t_line;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
}t_rect;

void	draw_rect(t_img *img, t_rect rect, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
void	swap(void *a, void *b, size_t size);
#endif
