/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:56:32 by allan             #+#    #+#             */
/*   Updated: 2023/07/17 21:10:00 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_hook(t_cub *cub)
{
	mlx_expose_hook(cub->config->mlx->win_ptr, &render, cub);
	mlx_loop_hook(cub->config->mlx->mlx_ptr, &render, cub);
	mlx_hook(cub->config->mlx->win_ptr, 17, 0, close_game, cub);
	mlx_key_hook(cub->config->mlx->win_ptr, &handle_keydown, cub);
	mlx_hook(cub->config->mlx->win_ptr,
		KEY_PRESS, KEY_PRESS_MASK, &handle_keypress, cub);
	mlx_loop(cub->config->mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	int		amount_line_in_file;
	char	**file;
	t_cub	*cub;

	ft_check_args(argc, argv);
	amount_line_in_file = ft_count_line_in_file(argv[1]);
	file = ft_read_file(argv[1], amount_line_in_file);
	if (file == NULL)
		exit(FAILURE);
	ft_check_config_file(file);
	if (check_map(&file[6]) == FAILURE)
	{
		free_double_pointer((void **)file);
		exit(FAILURE);
	}
	load_data(&cub, file);
	render(cub);
	init_hook(cub);
	destroy_game(cub);
	return (SUCESS);
}
