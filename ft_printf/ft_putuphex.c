/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:59:13 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 03:56:21 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphex(unsigned long number)
{
	int		count;

	count = 0;
	if (number >= 16)
		count += ft_putuphex(number / 16);
	count += write (1, &UPPER_BASE[(unsigned long)number % 16], 1);
	return (count);
}
