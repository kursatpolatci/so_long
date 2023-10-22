/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:52:50 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 14:50:39 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
