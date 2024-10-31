/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:51:44 by jramondo          #+#    #+#             */
/*   Updated: 2023/06/27 22:51:45 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrix_strlen(char **matrix)
{
	int	len;

	len = 0;
	if (matrix == NULL)
		return (-1);
	while (matrix[len] != 0)
		len++;
	return (len);
}
