/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:38:20 by jramondo          #+#    #+#             */
/*   Updated: 2023/06/27 22:38:21 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_strdel(char **matrix)
{
	int	index;
	int	size;

	index = 0;
	if (matrix == NULL)
		return ;
	size = ft_matrix_strlen(matrix);
	while (index < size)
	{
		ft_strdel(&matrix[index]);
		index++;
	}
	free(matrix);
}
