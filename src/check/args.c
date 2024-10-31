/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:08:16 by allan             #+#    #+#             */
/*   Updated: 2023/07/12 03:07:53 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf(ERROR_AMOUNT_ARGS);
		exit(FAILURE);
	}
	if (ft_check_ext(argv[1], "cub") != 0)
	{
		exit(FAILURE);
	}
	if (ft_check_if_file_exist(argv[1]))
		exit(FAILURE);
	return (SUCCESS);
}
