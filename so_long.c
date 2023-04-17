/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:28:00 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/12 19:08:25 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	ft_handle_error(argc, argv);
	mlx.map = ft_read_map(argv[1]);
	mlx.ptr = NULL;
	mlx.win = NULL;
	check_map(&mlx);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, mlx.loc.x_max * 64,
			mlx.loc.y_max * 64, "so_long");
	load_textures(&mlx);
	render_images(&mlx);
	mlx.loc.c_collected = 0;
	mlx_key_hook(mlx.win, &ft_key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, &ft_destroy_free, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
