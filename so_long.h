/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:30:06 by ashahin           #+#    #+#             */
/*   Updated: 2023/04/12 19:18:46 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE  64
# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_location
{
	int	p_x;
	int	p_y;
	int	e_x;
	int	e_y;
	int	c_x[20];
	int	c_y[20];
	int	c_count;
	int	e_count;
	int	p_count;
	int	c_found;
	int	e_found;
	int	p_found;
	int	c_collected;
	int	to_collect;
	int	x_max;
	int	y_max;
	int	steps;
}	t_location;

typedef struct s_image
{
	void	*mlx_image;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_textures
{
	t_image	floor;
	t_image	wall;
	t_image	exit;
	t_image	exit_open;
	t_image	player;
	t_image	collectables;
	t_image	enemy;
}	t_textures;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	char		**map;
	char		**visited;
	t_textures	textures;
	t_image		image;
	t_location	loc;
}	t_mlx;

//handle_error.c
int		ft_destroy_free(t_mlx *mlx);
void	ft_check_map_status(char *errorMessage, t_mlx *mlx);
void	free_map(char **map);
void	exit_with_error(char *errorMessage, t_mlx *mlx);
void	ft_handle_error(int argc, char **argv);

//map_read.c
char	**ft_read_map(char *mapfile);

//map_check.c
void	ft_check_map_p(t_mlx *mlx);
void	ft_check_map_c_e(t_mlx *mlx);
void	ft_check_line(t_mlx *mlx, int i, int opp);
void	ft_check_map_shape_unallowed_chars(t_mlx	*mlx);
void	check_map(t_mlx *mlx);

//load_textures.c
void	load_floor_wall_texture(t_mlx *mlx);
void	load_exit_texture(t_mlx *mlx);
void	load_player_texture(t_mlx *mlx);
void	load_collectables_texture(t_mlx *mlx);
void	load_textures(t_mlx *mlx);

//render_image.c
void	render_exit_open(t_mlx *mlx);
void	render_floor_wall_exit(t_mlx *mlx);
void	render_player(t_mlx *mlx);
void	render_collectables(t_mlx *mlx);
int		render_images(void *param);

//dfs.c
void	map_dimensions(t_mlx *mlx);
void	dfs(t_mlx *mlx, int y, int x);
void	copy_map(t_mlx *mlx);
void	validate_path(t_mlx *mlx);

// key_events
void	ft_you_won(t_mlx *mlx, int y, int x);
void	ft_check_exit_open(t_mlx *mlx);
void	ft_change_position(t_mlx *mlx, int y_new, int x_new);
void	ft_move_player(t_mlx *mlx, int y_new, int x_new);
int		ft_key_hook(int keycode, t_mlx *mlx);

#endif