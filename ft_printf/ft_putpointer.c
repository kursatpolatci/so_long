/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 02:00:02 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 04:12:22 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long number)
{
	int		count;

	count = 0;
	count += ft_putstr ("0x");
	count += ft_puthex(number);
	return (count);
}
