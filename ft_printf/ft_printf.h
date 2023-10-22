/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:26:25 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/24 16:19:44 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef LOWER_BASE
#  define LOWER_BASE "0123456789abcdef"
# endif

# ifndef UPPER_BASE
#  define UPPER_BASE "0123456789ABCDEF"
# endif

int	ft_printf(const char *str, ...);

int	ft_control(char c, va_list list);
int	ft_specifier(char c);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long number);
int	ft_putuns(unsigned long number);
int	ft_puthex(unsigned long number);
int	ft_putuphex(unsigned long number);
int	ft_putpointer(unsigned long number);

#endif