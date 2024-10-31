/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:56:58 by allan             #+#    #+#             */
/*   Updated: 2023/06/21 22:03:21 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	*create_vector(double x, double y)
{
	t_vector	*new_vector;

	new_vector = ft_calloc(sizeof(t_vector), 1);
	new_vector->x = x;
	new_vector->y = y;
	return (new_vector);
}
