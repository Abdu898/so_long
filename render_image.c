/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 05:36:42 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/11 18:50:53 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_exit_open(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->textures.exit.mlx_image);
	mlx_put_image_to_window(mlx->ptr, mlx->win,
		mlx->textures.exit_open.mlx_image,
		mlx->loc.e_x * TILE_SIZE, mlx->loc.e_y * TILE_SIZE);
}

void	render_floor_wall_exit(t_mlx *mlx)
{
	int		x;
	int		y;
	char	tile_type;

	y = -1;
	while (++y < mlx->loc.y_max)
	{
		x = -1;
		while (++x < mlx->loc.x_max)
		{
			tile_type = mlx->map[y][x];
			if (tile_type == '0')
				mlx_put_image_to_window(mlx->ptr, mlx->win,
					mlx->textures.floor.mlx_image,
					x * TILE_SIZE, y * TILE_SIZE);
			if (tile_type == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->win,
					mlx->textures.wall.mlx_image, x * TILE_SIZE, y * TILE_SIZE);
			if (tile_type == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win,
					mlx->textures.exit.mlx_image, x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

void	render_player(t_mlx *mlx)
{
	t_image	img;
	int		x;
	int		y;

	y = -1;
	while (mlx->map[++y])
	{
		x = -1;
		while (mlx->map[y][++x])
		{
			if (mlx->map[y][x] == 'P')
			{
				mlx->loc.p_x = x;
				mlx->loc.p_y = y;
			}
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win,
		mlx->textures.player.mlx_image,
		mlx->loc.p_x * TILE_SIZE, mlx->loc.p_y * TILE_SIZE);
}

void	render_collectables(t_mlx *mlx)
{
	t_image	img;
	int		x;
	int		y;

	mlx->loc.c_count = -1;
	y = -1;
	while (mlx->map[++y])
	{
		x = -1;
		while (mlx->map[y][++x])
		{
			if (mlx->map[y][x] == 'C')
			{
				mlx->loc.c_count++;
				mlx->loc.c_x[mlx->loc.c_count] = x;
				mlx->loc.c_y[mlx->loc.c_count] = y;
				mlx_put_image_to_window(mlx->ptr, mlx->win,
					mlx->textures.collectables.mlx_image,
					mlx->loc.c_x[mlx->loc.c_count] * TILE_SIZE,
					mlx->loc.c_y[mlx->loc.c_count] * TILE_SIZE);
			}
		}
	}
}

int	render_images(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_clear_window(mlx->ptr, mlx->win);
	render_floor_wall_exit(mlx);
	render_player(mlx);
	render_collectables(mlx);
	return (0);
}
