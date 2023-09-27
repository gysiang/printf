/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:11:08 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 00:26:10 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_format(va_list args, char format)
{
	int len;

	len = 0;
	if (format == 'c')
		len += ft_int_putchar_fd(va_arg(args, int), 1);
	else if (format == 's')
		len += ft_int_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		len += ft_voidtohex(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len += ft_int_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		len += ft_putnbr_unsigned((unsigned int)va_arg(args, int));
	else if (format == 'x')
		len += ft_intohex((unsigned int)va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_intohex((unsigned int)va_arg(args, int), "0123456789ABCDEF");
	else if (format == '%')
		len += ft_int_putchar_fd('%', 1);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	printed_len;
	va_list	args;

	i = 0;
	printed_len = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			printed_len++;
		}
		else
		{
			i++;
			printed_len += ft_format(args, s[i]);
		}
		i++;
	}
	va_end(args);
	return (i);
}

int	main(void)
{
	int	singlechar;
	int	num;
	char *string;
	unsigned int num1;

	singlechar = 'h';
	string = "ivan";
	num = 42;
	num1 = 4212345;
	ft_printf("This is a single char %c\n", singlechar);
	printf("This is a single char %c\n",singlechar);
	ft_printf("My name is %s. My char is %c\n", string, singlechar);
	printf("My name is %s. Mr char is %c\n", string, singlechar);
	ft_printf("Address of num: %p\n", (void *)&num);
	printf("Address of num: %p\n", (void *)&num);
	ft_printf("Decimal Base 10 number: %d\n", num);
	printf("Decimal Base 10 number: %d\n", num);
	ft_printf("Unsigned Int Decimal Base 10 number: %u\n", num1);
	printf("Unsigned Int Decimal Base 10 number: %u\n", num1);
	ft_printf("Print unsigned int number in lowercase hex format: %x\n", num1);
	printf("Print unsigned int number in lowercase hex format: %x\n", num1);
	ft_printf("Print unsigned int number in uppercase hex format: %X\n", num1);
	printf("Print unsigned int number in uppercase hex format: %X\n", num1);
	ft_printf("Prints out percentage sign : %%\n");
	printf("Prints out percentage sign : %%\n");
	return (0);
}
