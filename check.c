/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:19:08 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/29 17:50:47 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_object_decision(t_map *map, char c, int *x, int	*y)
{
	if (c == 'P')
	{
		map->player_x = *x;
		map->player_y = *y;
	}
	else if (c == 'E')
	{
		map->exit_x = *x;
		map->exit_y = *y;
	}
	else if (c == 'C')
	{
		map->collec_x = *x;
		map->collec_y = *y;
	}
}

void	ft_find_object(t_map *map, char c, int *x, int	*y)
{
	while (map->line[*y])
	{
		while (map->line[*y][*x])
		{
			if (map->line[*y][*x] == c)
			{
				ft_find_object_decision(map, c, x, y);
				return ;
			}
			*x += 1;
		}
		*x = 0;
		*y += 1;
	}
}

void	ft_assignment(t_map	*map)
{
	map->map_name = 0;
	map->line = 0;
	map->line_clone = 0;
	map->map_x = 0;
	map->map_y = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->collec_x = 0;
	map->collec_y = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->collected_c_count = 0;
}

t_map	*ft_check(int argc, char **argv)
{
	t_map	*map;

	map = ft_create_map(argc, argv);
	ft_check_fd_xpm(map);
	ft_check_rectangle(map);
	ft_check_object(map);
	ft_find_object(map, 'P', &map->player_x, &map->player_y);
	ft_find_object(map, 'E', &map->exit_x, &map->exit_y);
	ft_collectible_coin(map);
	return (map);
}

void	ft_process(t_map **map, int argc, char **argv)
{
	t_mlx		mlx;
	t_picture	img;

	ft_check_fd_ber(argv);
	(*map) = ft_check(argc, argv);
	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, (*map)->map_x * 64,
			(*map)->map_y * 64, "so_long");
	ft_img_init(&img, &mlx);
	ft_map_to_img((*map), &mlx, &img);
	mlx.map = (*map);
	mlx.img = &img;
	mlx_hook(mlx.window, 2, (1L << 0), ft_key_handler, &mlx);
	mlx_hook(mlx.window, 17, 0L, ft_close_game, &mlx);
	mlx_loop(mlx.init);
}
