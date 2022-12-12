/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:13:38 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/01 05:17:14 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/libft/libft.h"

int	main()
{
	int		fd;
	int		i;
	char	*line;

	//Standard Input, close it with CTRL + D
	line = (char *) malloc(sizeof(char *));
	fd = open("text.txt", O_RDONLY, 0);
	i = 1;
	while (line != (char *) 0)
	{
		line = get_next_line(fd);
		printf("Line%d: %s", i, line);
		free(line);
		i++;
	}
	line = get_next_line(fd);
	printf("Line%d: %s", i, line);
	int len = ft_strlen(line);
	printf("len%d: %d", i, len);
	free(line);
	return (0);
}

// int	main(void)
// {
// 	char	*str;
// 	int		fd;
// 	int		i;

// 	fd = open("text.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (printf("%s", str = get_next_line(fd)))
// 		i = 1;
// 	free(str);
// 	return (0);
// }