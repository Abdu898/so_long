/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:24:05 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/17 12:34:20 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_free(t_mlx *mlx)
{
	if (mlx->win && mlx->ptr)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->map)
		free_map(mlx->map);
	if (mlx->visited)
		free_map(mlx->visited);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		++i;
	}
	free(map);
	map = NULL;
}

void	ft_check_map_status(char *errorMessage, t_mlx *mlx)
{
	if (mlx->loc.c_count < 1 || mlx->loc.e_count != 1)
	{
		mlx->visited = NULL;
		exit_with_error(errorMessage, mlx);
	}
}

void	exit_with_error(char *errorMessage, t_mlx *mlx)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(errorMessage, 2);
	ft_putstr_fd("\n", 2);
	if (mlx)
		ft_destroy_free(mlx);
	exit(EXIT_FAILURE);
}

void	ft_handle_error(int argc, char **argv)
{
	char	*map_ext;
	char	**map;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid arguments; enter [map].ber\n", 2);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK) == -1)
	{
		ft_putstr_fd("Error: Invalid arguments; map file couldn't found.\n", 2);
		exit(EXIT_FAILURE);
	}
	map_ext = ft_strrchr(argv[1], '.');
	if (!map_ext || argv[1][ft_strlen(argv[1]) - 1] == '.')
	{
		ft_putstr_fd("Error: Invalid map format: [map].ber\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(map_ext, ".ber", ft_strlen(".ber")))
	{
		ft_putstr_fd("Error: Invalid map format: [map].ber\n", 2);
		exit(EXIT_FAILURE);
	}
}
