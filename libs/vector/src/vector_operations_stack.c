/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:31:39 by allan             #+#    #+#             */
/*   Updated: 2023/07/09 21:31:49 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	sum_stack(t_vector *first, t_vector *second)
{
	t_vector	new_vector;

	new_vector.x = first->x + second->x;
	new_vector.y = first->y + second->y;
	return (new_vector);
}

t_vector	mult_stack(t_vector *vector, double scale)
{
	t_vector	new_vector;

	new_vector.x = vector->x * scale;
	new_vector.y = vector->y * scale;
	return (new_vector);
}
