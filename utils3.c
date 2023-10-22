/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:10:18 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/29 16:37:01 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (1);
}

int	ft_is_another_obj(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] != '1' && str[j][i] != '0'
			&& str[j][i] != 'E' && str[j][i] != 'C'
			&& str[j][i] != 'P' && str[j][i] != '\n')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_print_map(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		ft_printf("%s\n", str[j]);
		j++;
	}
	ft_printf("\n");
}
