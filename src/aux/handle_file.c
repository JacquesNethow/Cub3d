/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:58:22 by allan             #+#    #+#             */
/*   Updated: 2023/07/13 22:57:01 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_lines(char **line_aux, char **file_line)
{
	free((*line_aux));
	free((*file_line));
	(*line_aux) = NULL;
	(*file_line) = NULL;
}

int	ft_count_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_line_in_file(char *file_name)
{
	int		count;
	int		fd;
	char	*file_line;
	char	*line_aux;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == FAILURE)
	{
		printf("3\n");
		perror(FILE_NOT_FOUND);
		return (FAILURE);
	}
	file_line = get_next_line(fd);
	while (file_line)
	{
		line_aux = ft_strtrim(file_line, " \n");
		if (ft_strlen(line_aux) || count > 6)
			count++;
		free_lines(&line_aux, &file_line);
		file_line = get_next_line(fd);
	}
	close(fd);
	free(file_line);
	return (count);
}

char	**ft_read_file(char *file_name, int amount_line_in_file)
{
	char	**file;
	char	*file_line;
	char	*line_aux;
	int		fd;
	int		index;

	index = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == FAILURE)
	{
		perror(FILE_NOT_FOUND);
		return (NULL);
	}
	file = ft_calloc(sizeof(char *), amount_line_in_file + 1);
	file_line = get_next_line(fd);
	while (file_line)
	{
		line_aux = ft_strtrim(file_line, "\n");
		if (ft_strlen(line_aux) || index > 6)
			file[index++] = ft_strdup(line_aux);
		free_lines(&line_aux, &file_line);
		file_line = get_next_line(fd);
	}
	free(file_line);
	return (file);
}
