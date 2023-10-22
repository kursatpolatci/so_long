/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:48:25 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/29 16:29:50 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_width(t_map *map)
{
	int	index;

	index = 0;
	map->map_y = ft_strlen2(map->line);
	while (map->line[0][index])
	{
		if (map->line[0][index] == '\n')
			break ;
		index++;
	}
	map->map_x = index;
}

int	ft_full_wall_horizontal(char **str, int index)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str[0]);
	while (i < len)
	{
		if (index == (ft_strlen2(str) - 1))
		{
			if (i == len - 1)
				break ;
			if (str[index][i] != '1')
				return (0);
		}
		else
		{
			if (str[index][i] == '\n' && (i == len - 1))
				break ;
			if (str[index][i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_full_wall_vertical(char **str, int index)
{
	int	i;
	int	len;

	len = ft_strlen2(str);
	i = 0;
	while (i < len)
	{
		if (str[i][index] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_rectangle(char **map)
{
	int	len;
	int	j;
	int	i;

	len = ft_strlen(map[0]);
	j = 0;
	while (map[j])
	{
		i = ft_strlen(map[j]);
		if (j == ft_strlen2(map) - 1)
		{
			len--;
			if (i != len)
				return (0);
		}
		if (i != len)
			return (0);
		j++;
	}
	return (1);
}

void	ft_check_rectangle(t_map *map)
{
	int	len;

	len = ft_strlen2(map->line);
	if (len <= 2)
		ft_print_error_extended("Invalid len Map", map);
	if (len > 20)
		ft_print_error_extended("Map doesn't fit to screen", map);
	if ((ft_strlen(map->line[0]) - 1) > 40)
		ft_print_error_extended("Map doesn't fit to screen", map);
	if (!ft_is_rectangle(map->line))
		ft_print_error_extended("Map is not rectangle", map);
	if (!ft_full_wall_horizontal(map->line, 0)
		|| !ft_full_wall_horizontal(map->line, len - 1))
		ft_print_error_extended("Map is not surrounded by walls-", map);
	if (!ft_full_wall_vertical(map->line, 0)
		|| !ft_full_wall_vertical(map->line, ft_strlen(map->line[0]) - 2))
		ft_print_error_extended("Map is not surrounded by walls?", map);
	if (!ft_is_another_obj(map->line))
		ft_print_error_extended("Invalid object in map", map);
	ft_map_width(map);
}
