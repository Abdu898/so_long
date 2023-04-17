/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:39:54 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/12 18:22:19 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_you_won(t_mlx *mlx, int y, int x)
{
	mlx->loc.steps++;
	ft_printf("Steps: %d\t Magic Mashrooms: %d/%d\n",
		mlx->loc.steps, mlx->loc.c_collected, mlx->loc.to_collect);
	mlx_put_image_to_window(mlx->ptr, mlx->win,
		mlx->textures.player.mlx_image, x * TILE_SIZE, y * TILE_SIZE);
	ft_printf("Enjoy the trip! See you next fall!\n");
	ft_destroy_free(mlx);
	exit(EXIT_SUCCESS);
}

void	ft_check_exit_open(t_mlx *mlx)
{
	if (mlx->loc.c_collected == mlx->loc.to_collect)
	{
		render_exit_open(mlx);
		mlx->map[mlx->loc.e_y][mlx->loc.e_x] = 'D';
		ft_printf("you collected all the Magic Mashrooms\n"
			"your trip awaits you!\n");
	}
}

void	ft_change_position(t_mlx *mlx, int y_new, int x_new)
{
	char	tile_type;

	tile_type = mlx->map[mlx->loc.p_y][mlx->loc.p_x];
	if (tile_type == '0' || tile_type == 'C' || tile_type == 'P')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->textures.floor.mlx_image,
			mlx->loc.p_x * TILE_SIZE, mlx->loc.p_y * TILE_SIZE);
	}
	else if (tile_type == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->textures.exit.mlx_image,
			mlx->loc.p_x * TILE_SIZE, mlx->loc.p_y * TILE_SIZE);
	mlx_put_image_to_window(mlx->ptr, mlx->win,
		mlx->textures.player.mlx_image, x_new * TILE_SIZE, y_new * TILE_SIZE);
	mlx->loc.p_y = y_new;
	mlx->loc.p_x = x_new;
	mlx->loc.steps++;
	ft_printf("Steps: %d\t Magic Mashrooms: %d/%d\n",
		mlx->loc.steps, mlx->loc.c_collected, mlx->loc.to_collect);
}

void	ft_move_player(t_mlx *mlx, int y_new, int x_new)
{
	if (mlx->map[y_new][x_new] == '1')
		return ;
	else if (mlx->map[y_new][x_new] == '0' || mlx->map[y_new][x_new] == 'C'
		|| mlx->map[y_new][x_new] == 'E' || mlx->map[y_new][x_new] == 'P')
	{
		if (mlx->map[y_new][x_new] == 'C')
		{
			mlx->map[y_new][x_new] = '0';
			mlx->loc.c_collected++;
			ft_printf("You collected %d Magic Mashrooms out of %d\n",
				mlx->loc.c_collected, mlx->loc.to_collect);
			ft_check_exit_open(mlx);
		}
		ft_change_position(mlx, y_new, x_new);
	}
	else if (mlx->map[y_new][x_new] == 'D')
		ft_you_won(mlx, y_new, x_new);
}

int	ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		ft_destroy_free(mlx);
	else if (keycode == D_KEY)
		ft_move_player(mlx, mlx->loc.p_y, mlx->loc.p_x + 1);
	else if (keycode == A_KEY)
		ft_move_player(mlx, mlx->loc.p_y, mlx->loc.p_x - 1);
	else if (keycode == W_KEY)
		ft_move_player(mlx, mlx->loc.p_y - 1, mlx->loc.p_x);
	else if (keycode == S_KEY)
		ft_move_player(mlx, mlx->loc.p_y + 1, mlx->loc.p_x);
	return (0);
}
