/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:48:36 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/29 14:36:37 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_split(char ***str)
{
	int	index;

	index = 0;
	while ((*str)[index])
	{
		if ((*str)[index] != NULL)
			free((*str)[index]);
		index++;
	}
	free(*str);
	*str = NULL;
}

void	ft_free_map(t_map *map)
{
	if (map->line)
		ft_free_map_split(&map->line);
	if (map->line_clone)
		ft_free_map_split(&map->line_clone);
	if (map)
		free(map);
}

void	ft_check_fd_xpm(t_map *map)
{
	int	fd;

	fd = open("./textures/player.xpm", O_RDONLY);
	if (fd < 0)
		ft_print_error_extended("xpm file error!", map);
	close(fd);
	fd = open("./textures/coin.xpm", O_RDONLY);
	if (fd < 0)
		ft_print_error_extended("xpm file error!", map);
	close(fd);
	fd = open("./textures/wall.xpm", O_RDONLY);
	if (fd < 0)
		ft_print_error_extended("xpm file error!", map);
	close(fd);
	fd = open("./textures/ground.xpm", O_RDONLY);
	if (fd < 0)
		ft_print_error_extended("xpm file error!", map);
	close(fd);
	fd = open("./textures/exit.xpm", O_RDONLY);
	if (fd < 0)
		ft_print_error_extended("xpm file error!", map);
	close(fd);
}

void	ft_check_fd_ber(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_print_error("Map does not open (fd)!");
	close (fd);
}

int	ft_close_game(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img->player);
	mlx_destroy_image(mlx->init, mlx->img->coin);
	mlx_destroy_image(mlx->init, mlx->img->wall);
	mlx_destroy_image(mlx->init, mlx->img->ground);
	mlx_destroy_image(mlx->init, mlx->img->exit);
	ft_free_map(mlx->map);
	mlx_destroy_window(mlx->init, mlx->window);
	exit(1);
}
