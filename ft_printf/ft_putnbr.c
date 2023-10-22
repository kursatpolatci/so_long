/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:53:57 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 03:52:46 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long number)
{
	int		count;

	count = 0;
	if (number < 0)
	{
		number *= -1;
		count += ft_putchar('-');
	}
	if (number >= 10)
		count += ft_putnbr(number / 10);
	count += ft_putchar ('0' + (number % 10));
	return (count);
}
