/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:24:05 by ashahin           #+#    #+#             */
/*   Updated: 2022/12/08 18:34:35 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_err(int argc, char **argv)
{
	char	*map;

	if (argc != 2)
	{
		ft_putstr_fd("ERROR\nInvalid arguments\n", 2);
		return (1);
	}
	map = ft_strrchr(argv[1], '.');
	if (!map)
	{
		ft_putstr_fd("Error\nInvalid map format: map.ber\n", 2);
		return (2);
	}
	if (ft_strncmp(map, ".ber", ft_strlen(map)))
	{
		ft_putstr_fd("Error\nInvalid map format: map.ber\n", 2);
		return (2);
	}
	return (0);
}