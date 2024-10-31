/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:09:49 by allan             #+#    #+#             */
/*   Updated: 2023/06/28 21:23:58 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H

# define VECTOR_H
# include <math.h>
# include "../../libft/libft.h"

typedef struct s_vector
{
	double	x;
	double	y;
}t_vector;

t_vector	*create_vector(double x, double y);
void		delete_vector(t_vector **vector);
t_vector	*mult(t_vector *vector, double scale);
t_vector	mult_stack(t_vector *vector, double scale);
t_vector	*normalize(t_vector *vector);
t_vector	*sum(t_vector *first, t_vector *second);
t_vector	sum_stack(t_vector *first, t_vector *second);
t_vector	*sub(t_vector *first, t_vector *second);
double		mag(t_vector *vector);
void		rotate(t_vector **vector, double angle);
#endif
