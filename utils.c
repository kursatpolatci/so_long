/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:39:07 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/27 19:58:05 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

void	ft_print_error_extended(char *str, t_map *map)
{
	ft_printf("%s", str);
	ft_free_map(map);
	exit(1);
}

int	ft_strlen2(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_find_str(char *src, char *base, int *index)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (src[*index] != base[i])
			return (0);
		i++;
		*index += 1;
	}
	return (1);
}

void	ft_memset(void	*content, char c, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		((char *)content)[index] = c;
		index++;
	}
}
