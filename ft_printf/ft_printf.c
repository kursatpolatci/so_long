/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:28:56 by kpolatci          #+#    #+#             */
/*   Updated: 2023/08/16 02:09:15 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!ft_specifier (*(str + 1)))
			{
				str++;
				continue ;
			}
			count += ft_control (*(str + 1), ap);
			str++;
		}
		else
			count += write (1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}

/*
#include <stdio.h>
int main()
{
    char *s = "Merhaba";
    int number = 5;
    int *nbr_ptr = &number;
    char *str_ptr = s;

    printf("%s, %d, %p, %s\n",s,number,nbr_ptr,str_ptr);
    ft_printf("%s, %d, %p, %s\n",s,number,nbr_ptr,str_ptr);

    printf("%u, %x, %X\n",-12, 25, 155);
    ft_printf("%u, %x, %X\n",-12, 25, 155);
    

    int b = 17;
    char *a = "selam";
    ft_printf("%c\n", a[2]);
    printf("%c\n", a[2]);
    ft_printf("%p\n", a);
    printf("%p\n", a);
    ft_printf("%p\n", &a);
    printf("%p\n", &a);
    ft_printf("%p\n", &b);
    printf("%p\n", &b);
    ft_printf("%d\n", b);
    printf("%d\n", b);
    ft_printf("%x\n", b);
    printf("%x\n", b);
    ft_printf("%%%d\n", b);
    printf("%%%d\n", b);
    ft_printf("%%s\n", a);
    printf("%%s\n", a);+
    ft_printf("%a\n");
    printf("%a\n");
    ft_printf("%c\n", '1');
    printf("%c\n", '1');
    ft_printf("%s\n", "1");
    printf("%s\n", "1");
    ft_printf("%p\n", "heloo");
    printf("%p\n", "heloo");
    ft_printf("");
    printf("");
    ft_printf("%c%c\n", 'a');
    printf("%c%c\n", 'a');
    ft_printf("%u\n", 2147483647);
    printf("%u\n", 2147483647);
    ft_printf("%i\n", 2147483648);
    printf("%i\n", 2147483648);
    ft_printf("%u\n", 2147483649);
    printf("%u\n", 2147483649);
    ft_printf("%i\n", 2147483649);
    printf("%i\n", 2147483649);
    ft_printf("%d\n", 2147483648);
    printf("%d\n", 2147483648);
    ft_printf("%d\n", 2147483649);
    printf("%d\n", 2147483649);
    ft_printf("%d\n", 2147483650);
    printf("%d\n", 2147483650);
    ft_printf("%d\n", -2147483649);
    printf("%d\n", -2147483649);
    ft_printf("%u\n", -2147483647);
    printf("%u\n", -2147483647);
    ft_printf("%u\n", -2147483648);
    printf("%u\n", -2147483648);
    ft_printf("%i\n", -2147483649);
    printf("%i\n", -2147483649);
    ft_printf("%d\n" , 0);
    printf("%d\n" , 0);
    ft_printf("%c\n" ,'0');
    printf("%c\n" ,'0');
    ft_printf("%s\n" ,"0");
    printf("%s\n" ,"0");
    ft_printf("%x\n" ,0);
    printf("%x\n" ,0);
    ft_printf("%x\n" ,-1);
    printf("%x\n" ,-1);
    ft_printf("", "");
    printf("", "");
    printf("%s%","merhaba");
    printf("\n");
    ft_printf("%s%","merhaba");
    printf("\n");
}*/