/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:57:08 by allan             #+#    #+#             */
/*   Updated: 2023/07/09 21:31:34 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	*mult(t_vector *vector, double scale)
{
	t_vector	*new_vector;

	new_vector = create_vector(vector->x * scale, vector->y * scale);
	return (new_vector);
}

t_vector	*normalize(t_vector *vector)
{
	double		mag_vector;
	t_vector	*new_vector;

	mag_vector = mag(vector);
	new_vector = mult(vector, 1 / mag_vector);
	return (new_vector);
}

t_vector	*sum(t_vector *first, t_vector *second)
{
	t_vector	*new_vector;

	new_vector = create_vector(first->x + second->x, first->y + second->y);
	return (new_vector);
}

t_vector	*sub(t_vector *first, t_vector *second)
{
	t_vector	*new_vector;

	new_vector = create_vector(first->x - second->x, first->y - second->y);
	return (new_vector);
}
