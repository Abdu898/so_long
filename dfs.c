/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 07:53:14 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/12 23:55:15 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_dimensions(t_mlx *mlx)
{
	mlx->loc.y_max = 0;
	mlx->loc.x_max = 0;
	while (mlx->map[mlx->loc.y_max])
		mlx->loc.y_max++;
	mlx->loc.x_max = ft_strlen(mlx->map[0]);
}

void	copy_map(t_mlx *mlx)
{
	int	len;
	int	i;

	len = 0;
	while (mlx->map[len])
		len++;
	mlx->visited = (char **) ft_calloc((len + 1), sizeof(char *));
	if (!(mlx->visited))
		exit_with_error("Failed allocating memory for \"visited\" buffer", mlx);
	mlx->visited[len] = NULL;
	i = -1;
	while (++i < len)
		mlx->visited[i] = ft_strdup(mlx->map[i]);
}

void	dfs(t_mlx *mlx, int y, int x)
{
	if (mlx->visited[y][x] == '1' || mlx->map[y][x] == '1')
		return ;
	if (mlx->map[y][x] == 'C')
		mlx->loc.c_found++;
	else if (mlx->map[y][x] == 'E')
		mlx->loc.e_found++;
	mlx->visited[y][x] = '1';
	dfs(mlx, y + 1, x);
	dfs(mlx, y - 1, x);
	dfs(mlx, y, x + 1);
	dfs(mlx, y, x - 1);
}

void	validate_path(t_mlx *mlx)
{
	mlx->loc.c_found = 0;
	mlx->loc.e_found = 0;
	map_dimensions(mlx);
	copy_map(mlx);
	dfs(mlx, mlx->loc.p_y, mlx->loc.p_x);
	if (mlx->loc.e_found != 1 || mlx->loc.c_found != mlx->loc.c_count)
		exit_with_error("Invalid map: no valid path to Exit/Collectables", mlx);
	free_map(mlx->visited);
	mlx->visited = NULL;
}
