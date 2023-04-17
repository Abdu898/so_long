/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:41:27 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/13 01:12:07 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *mapfile)
{
	int		fd;
	char	*line;
	char	*all_lines;
	char	*tmp;
	char	**map;

	fd = open(mapfile, O_RDONLY, 0);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strdup(all_lines);
		if (all_lines)
			free(all_lines);
		all_lines = myft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	map = ft_split(all_lines, '\n');
	free(all_lines);
	return (map);
}
