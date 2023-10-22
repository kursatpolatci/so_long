/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:18:29 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/28 14:33:30 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_objects(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->line[i])
	{
		j = 0;
		while (map->line[i][j])
		{
			if (map->line[i][j] == 'P')
				map->p_count += 1;
			if (map->line[i][j] == 'C')
				map->c_count += 1;
			if (map->line[i][j] == 'E')
				map->e_count += 1;
			j++;
		}
		i++;
	}
}

void	ft_check_object(t_map *map)
{
	ft_count_objects(map);
	if (map->p_count != 1)
		ft_print_error_extended("Invalid player count.", map);
	if (map->e_count != 1)
		ft_print_error_extended("Invalid exit count.", map);
	if (map->c_count < 1)
		ft_print_error_extended("Invalid coin count.", map);
}
