/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:06:32 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/17 15:38:19 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_p(t_mlx *mlx)
{
	int	i;
	int	j;

	mlx->loc.p_count = 0;
	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->loc.p_count++;
				mlx->loc.p_x = j;
				mlx->loc.p_y = i;
			}
		}
	}
	if (mlx->loc.p_count != 1)
	{
		mlx->visited = NULL;
		exit_with_error("Invalid map: must be only 1 P in the map.", mlx);
	}
}

void	ft_check_map_c_e(t_mlx *mlx)
{
	int			i;
	int			j;

	i = -1;
	mlx->loc.c_count = 0;
	mlx->loc.e_count = 0;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'C')
				mlx->loc.c_count++;
			else if (mlx->map[i][j] == 'E')
			{
				mlx->loc.e_count++;
				mlx->loc.e_y = i;
				mlx->loc.e_x = j;
			}
		}
	}
	mlx->loc.to_collect = mlx->loc.c_count;
	ft_check_map_status("Invalid map: must be only one E"
		" and at least one C in the map.", mlx);
}

void	ft_check_line(t_mlx *mlx, int i, int opp)
{
	int	j;

	if (opp == 1)
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] != '1')
				ft_check_map_status("Invalid map: map is not surrounded.", mlx);
		}
	}
	else if (mlx->map[i][0] != '1'
	|| mlx->map[i][ft_strlen(mlx->map[i]) - 1] != '1')
		ft_check_map_status("Invalid map: map is not surrounded.", mlx);
}

void	ft_check_map_shape_unallowed_chars(t_mlx	*mlx)
{
	int		i;
	int		j;
	size_t	width;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if ((mlx->map[i][j] != '0' && mlx->map[i][j] != '1' &&
				mlx->map[i][j] != 'P' && mlx->map[i][j] != 'C' &&
				mlx->map[i][j] != 'E'))
				ft_check_map_status("Invalid map: unallowed"
					" char/s found in the map.", mlx);
		}
	}
	i = 0;
	width = ft_strlen(mlx->map[i]);
	while (mlx->map[++i])
		if (ft_strlen(mlx->map[i]) != width)
			ft_check_map_status("Invalid map: "
				"map shape must be rectanglar.", mlx);
}

void	check_map(t_mlx *mlx)
{
	int	i;

	i = -1;
	ft_check_map_shape_unallowed_chars(mlx);
	while (mlx->map[++i])
	{
		if (i == 0 || !mlx->map[i + 1])
			ft_check_line(mlx, i, 1);
		else
			ft_check_line(mlx, i, 0);
	}
	ft_check_map_c_e(mlx);
	ft_check_map_p(mlx);
	validate_path(mlx);
	mlx->loc.steps = 0;
	mlx->loc.c_collected = 0;
}
