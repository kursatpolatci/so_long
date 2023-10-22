/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:55:15 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 03:55:05 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned long number)
{
	int		count;

	count = 0;
	if (number >= 10)
		count += ft_putuns(number / 10);
	count += ft_putchar ('0' + (number % 10));
	return (count);
}
