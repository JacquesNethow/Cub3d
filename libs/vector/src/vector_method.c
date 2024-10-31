/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:57:06 by allan             #+#    #+#             */
/*   Updated: 2023/06/21 22:04:40 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

double	mag(t_vector *vector)
{
	double	result;

	result = sqrt(pow(vector->x, 2) + pow(vector->y, 2));
	return (result);
}

void	rotate(t_vector **vector, double angle)
{
	t_vector	aux;

	aux = **vector;
	(*vector)->x = aux.x * cos(angle) - aux.y * sin(angle);
	(*vector)->y = aux.x * sin(angle) + aux.y * cos(angle);
}
