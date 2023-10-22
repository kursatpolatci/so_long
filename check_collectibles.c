/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:30:37 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/29 18:38:37 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(t_map *map, int x, int y)
{
	if (map->line[y][x] != '1' && map->line_clone[y][x] != '1')
	{
		map->line_clone[y][x] = '1';
		if (map->line[y][x] == 'K')
			return (1);
		if (ft_move(map, x, y + 1))
			return (1);
		if (ft_move(map, x + 1, y))
			return (1);
		if (ft_move(map, x, y - 1))
			return (1);
		if (ft_move(map, x - 1, y))
			return (1);
	}
	return (0);
}

void	ft_calculate_coin(t_map *map)
{
	ft_copy_map(map);
	map->collected_c_count += ft_move(map, map->player_x, map->player_y);
	ft_free_map_split(&map->line_clone);
}

void	ft_temporary_coin(t_map *map)
{
	map->line[map->collec_y][map->collec_x] = 'K';
	ft_calculate_coin(map);
	map->line[map->collec_y][map->collec_x] = 'C';
}

void	ft_collectible_coin(t_map *map)
{
	int	count;

	count = map->c_count;
	map->line[map->exit_y][map->exit_x] = '1';
	while (count > 0)
	{
		ft_find_object(map, 'C', &map->collec_x, &map->collec_y);
		ft_temporary_coin(map);
		map->collec_x += 1;
		count--;
	}
	map->line[map->exit_y][map->exit_x] = 'E';
	if (!ft_accessibility_exit(map))
		ft_print_error_extended("Can not reach to exit!", map);
	if (!(map->collected_c_count == map->c_count))
		ft_print_error_extended("Can not reach to coin!", map);
}

int	ft_accessibility_exit(t_map	*map)
{
	map->line[map->exit_y][map->exit_x] = 'K';
	ft_copy_map(map);
	if (ft_move(map, map->player_x, map->player_y))
	{
		map->line[map->exit_y][map->exit_x] = 'E';
		ft_free_map_split(&map->line_clone);
		return (1);
	}
	ft_free_map_split(&map->line_clone);
	return (0);
}
