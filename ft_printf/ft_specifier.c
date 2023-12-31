/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:16:15 by kpolatci          #+#    #+#             */
/*   Updated: 2023/09/28 14:34:56 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'x'
		|| c == 'X' || c == 'p' || c == 'u' || c == '%')
		return (1);
	return (0);
}
