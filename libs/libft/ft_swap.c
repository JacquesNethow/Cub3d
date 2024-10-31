/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:55:22 by allan             #+#    #+#             */
/*   Updated: 2023/06/21 22:56:52 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void	*aux;

	aux = ft_calloc(size, 1);
	ft_memcpy(aux, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, aux, size);
}
