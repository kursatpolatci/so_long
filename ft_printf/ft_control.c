/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:31:40 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 03:40:06 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(list, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (c == 'x')
		count += ft_puthex(va_arg(list, unsigned int));
	else if (c == 'X')
		count += ft_putuphex(va_arg(list, unsigned int));
	else if (c == 'p')
		count += ft_putpointer(va_arg(list, unsigned long));
	else if (c == 'u')
		count += ft_putuns(va_arg(list, unsigned int));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}
