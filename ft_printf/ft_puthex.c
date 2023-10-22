/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 01:56:27 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 03:51:44 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long number)
{
	int		count;

	count = 0;
	if (number >= 16)
		count += ft_puthex (number / 16);
	count += write (1, &LOWER_BASE[(unsigned long)number % 16], 1);
	return (count);
}
