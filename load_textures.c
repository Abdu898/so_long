/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 06:57:27 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/11 19:30:17 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_floor_wall_texture(t_mlx *mlx)
{
	mlx->textures.floor.mlx_image = mlx_xpm_file_to_image(mlx->ptr,
			"textures/xpm_formats/floor.xpm", &(mlx->textures.floor.width),
			&(mlx->textures.floor.height));
	if (!mlx->textures.floor.mlx_image)
		exit_with_error("Failed to load floor texture", mlx);
	mlx->textures.floor.buffer = (char *)mlx_get_data_addr(
			mlx->textures.floor.mlx_image, &(mlx->textures.floor.pixel_bits),
			&(mlx->textures.floor.line_bytes), &(mlx->textures.floor.endian));
	if (!mlx->textures.floor.buffer)
		exit_with_error("Failed to process floor texture", mlx);
	mlx->textures.wall.mlx_image = mlx_xpm_file_to_image(mlx->ptr,
			"textures/xpm_formats/wall.xpm", &(mlx->textures.wall.width),
			&(mlx->textures.wall.height));
	if (!mlx->textures.wall.mlx_image)
		exit_with_error("Failed to load wall texture", mlx);
	mlx->textures.wall.buffer = (char *)mlx_get_data_addr(
			mlx->textures.wall.mlx_image, &(mlx->textures.wall.pixel_bits),
			&(mlx->textures.wall.line_bytes), &(mlx->textures.wall.endian));
	if (!mlx->textures.wall.buffer)
		exit_with_error("Failed to process wall texture", mlx);
}

void	load_exit_texture(t_mlx *mlx)
{
	mlx->textures.exit.mlx_image = mlx_xpm_file_to_image(mlx->ptr,
			"textures/xpm_formats/exit.xpm", &(mlx->textures.exit.width),
			&(mlx->textures.exit.height));
	if (!mlx->textures.exit.mlx_image)
		exit_with_error("Failed to load exit texture", mlx);
	mlx->textures.exit.buffer = (char *)mlx_get_data_addr(
			mlx->textures.exit.mlx_image, &(mlx->textures.exit.pixel_bits),
			&(mlx->textures.exit.line_bytes), &(mlx->textures.exit.endian));
	if (!mlx->textures.exit.buffer)
		exit_with_error("Failed to process exit texture", mlx);
	mlx->textures.exit_open.mlx_image = mlx_xpm_file_to_image(mlx->ptr,
			"textures/xpm_formats/exit_open.xpm",
			&(mlx->textures.exit_open.width),
			&(mlx->textures.exit_open.height));
	if (!mlx->textures.exit_open.mlx_image)
		exit_with_error("Failed to load exit texture", mlx);
	mlx->textures.exit_open.buffer = (char *)mlx_get_data_addr(
			mlx->textures.exit_open.mlx_image,
			&(mlx->textures.exit_open.pixel_bits),
			&(mlx->textures.exit_open.line_bytes),
			&(mlx->textures.exit_open.endian));
	if (!mlx->textures.exit_open.buffer)
		exit_with_error("Failed to process exit texture", mlx);
}

void	load_player_texture(t_mlx *mlx)
{
	mlx->textures.player.mlx_image = mlx_xpm_file_to_image(mlx->ptr,
			"textures/xpm_formats/player.xpm", &(mlx->textures.player.width),
			&(mlx->textures.player.height));
	if (!mlx->textures.player.mlx_image)
		exit_with_error("Failed to load player texture", mlx);
	mlx->textures.player.buffer = (char *)mlx_get_data_addr(
			mlx->textures.player.mlx_image, &(mlx->textures.player.pixel_bits),
			&(mlx->textures.player.line_bytes), &(mlx->textures.player.endian));
	if (!mlx->textures.player.buffer)
		exit_with_error("Failed to process player texture", mlx);
}

void	load_collectables_texture(t_mlx *mlx)
{
	mlx->textures.collectables.mlx_image = mlx_xpm_file_to_image(mlx->ptr,
			"textures/xpm_formats/collectables.xpm",
			&(mlx->textures.collectables.width),
			&(mlx->textures.collectables.height));
	if (!mlx->textures.collectables.mlx_image)
		exit_with_error("Failed to load collectables texture", mlx);
	mlx->textures.collectables.buffer = (char *)mlx_get_data_addr(
			mlx->textures.collectables.mlx_image,
			&(mlx->textures.collectables.pixel_bits),
			&(mlx->textures.collectables.line_bytes),
			&(mlx->textures.collectables.endian));
	if (!mlx->textures.collectables.buffer)
		exit_with_error("Failed to process collectables texture", mlx);
}

void	load_textures(t_mlx *mlx)
{
	load_floor_wall_texture(mlx);
	load_exit_texture(mlx);
	load_player_texture(mlx);
	load_collectables_texture(mlx);
}
