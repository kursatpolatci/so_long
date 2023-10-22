/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:05:30 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/28 17:05:30 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_init(t_picture *img, t_mlx *mlx)
{
	img->player = mlx_xpm_file_to_image(mlx->init, "./textures/player.xpm",
			&img->x, &img->y);
	img->coin = mlx_xpm_file_to_image(mlx->init, "./textures/coin.xpm", &img->x,
			&img->y);
	img->ground = mlx_xpm_file_to_image(mlx->init, "./textures/ground.xpm",
			&img->x, &img->y);
	img->wall = mlx_xpm_file_to_image(mlx->init, "./textures/wall.xpm", &img->x,
			&img->y);
	img->exit = mlx_xpm_file_to_image(mlx->init, "./textures/exit.xpm", &img->x,
			&img->y);
}

void	ft_img_send(t_mlx *mlx, t_picture *img, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(mlx->init, mlx->window, img->coin, mlx->pixel_x,
			mlx->pixel_y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->init, mlx->window, img->exit, mlx->pixel_x,
			mlx->pixel_y);
	else if (c == '0')
		mlx_put_image_to_window(mlx->init, mlx->window, img->ground,
			mlx->pixel_x, mlx->pixel_y);
	else if (c == '1')
		mlx_put_image_to_window(mlx->init, mlx->window, img->wall, mlx->pixel_x,
			mlx->pixel_y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->init, mlx->window, img->player,
			mlx->pixel_x, mlx->pixel_y);
}

void	ft_map_to_img(t_map *map, t_mlx *mlx, t_picture *img)
{
	int	x;
	int	y;

	mlx->pixel_y = 0;
	y = -1;
	while (map->line[++y])
	{
		x = -1;
		mlx->pixel_x = 0;
		while (map->line[y][++x])
		{
			ft_img_send(mlx, img, map->line[y][x]);
			mlx->pixel_x += 64;
		}
		mlx->pixel_y += 64;
	}
}

void	ft_shift(t_mlx *mlx, int x, int y)
{
	static int	step_count = 0;

	if (mlx->map->collected_c_count == 0 && mlx->map->line[y][x] == 'E')
	{
		mlx->map->line[mlx->map->player_y][mlx->map->player_x] = '0';
		mlx->map->line[y][x] = 'P';
		mlx->map->player_y = y;
		mlx->map->player_x = x;
		step_count++;
		ft_printf("Move Count:%d\n", step_count);
		ft_printf("Game finish :)");
		ft_close_game(mlx);
	}
	else if (mlx->map->line[y][x] != '1' && mlx->map->line[y][x] != 'E')
	{
		if (mlx->map->line[y][x] == 'C')
			mlx->map->collected_c_count -= 1;
		mlx->map->line[mlx->map->player_y][mlx->map->player_x] = '0';
		mlx->map->line[y][x] = 'P';
		mlx->map->player_y = y;
		mlx->map->player_x = x;
		step_count++;
		ft_printf("Move Count: %d\n", step_count);
	}
}

int	ft_key_handler(int keycode, t_mlx *mlx)
{
	if (keycode == 2)
		ft_shift(mlx, mlx->map->player_x + 1, mlx->map->player_y);
	else if (keycode == 13)
		ft_shift(mlx, mlx->map->player_x, mlx->map->player_y - 1);
	else if (keycode == 0)
		ft_shift(mlx, mlx->map->player_x - 1, mlx->map->player_y);
	else if (keycode == 1)
		ft_shift(mlx, mlx->map->player_x, mlx->map->player_y + 1);
	else if (keycode == 53)
		ft_close_game(mlx);
	ft_map_to_img(mlx->map, mlx, mlx->img);
	return (keycode);
}
