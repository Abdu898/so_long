/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:28:00 by ashahin           #+#    #+#             */
/*   Updated: 2022/12/08 18:59:50 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// int	deal_key(int key, void *param)
// {
// 	ft_putchar_fd('X', 1);
// 	return (0);
// }

char	**ft_read_map(char *mapfile)
{
	char	*line;
	char	
	char	*map;
	int		fd;
	int		i;
	int		read_ret;

	fd = open(mapfile, O_RDONLY, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	i = -1;
	while (read_ret > 0)
	{
		line = get_next_line(fd);
		map = ft_strjoin(map, line);
		free(line);
		
	}
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (handle_err(argc, argv))
		return (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_loop(mlx_ptr);
	ft_read_map(argv[1]);
	return (0);
}
