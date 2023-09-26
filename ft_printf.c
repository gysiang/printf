/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:11:08 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/26 20:28:06 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
}

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int ft_voidtohex(void *p)
{
	unsigned long long addr;
	int	i;
	int	len;
	char hex[16];

	len = 0;
	i = 15;
	addr = (unsigned long long)p;
	while (addr > 0)
	{
		i--;
		hex[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		len++;
	}
	ft_putstr_fd(&hex[i], 1);
	return (len);
}

static int	ft_intohex(unsigned int s, char *base)
{
	unsigned int	c;
	int	i;
	int	len;
	char	hex[16];

	len = 0;
	i = 15;
	c = (unsigned int)s;
	while (c > 0)
	{
		hex[i] = base[c % 16];
		c /= 16;
		i--;
		len++;
	}
	ft_putstr_fd(&hex[i], 1);
	return (len);
}

static int	ft_format(va_list args, char format)
{
	int len;

	len = 0;
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		len++;
	}
	else if (format == 's')
	{
		char *s;
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
		len += ft_strlen(s);
	}
	else if (format == 'p')
	{
		len += ft_voidtohex(va_arg(args, void *));
	}
	else if (format == 'd')
	{
		int	num;
		num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
		if (num < 0)
			len += ft_numlen(-num) + 1;
		else
			len += ft_numlen(num); 
	}
	else if (format == 'u')
	{
		unsigned int num;
		num = (unsigned int)va_arg(args, int);
		ft_putnbr_unsigned(num);
		len += ft_numlen(num);
	}
	else if (format == 'x')
	{
		unsigned int s;
		s = (unsigned int)va_arg(args, int);
		len += ft_intohex(s, "0123456789abcdef");
	}
	else if (format == 'X')
	{
		unsigned int s;
		s = (unsigned int)va_arg(args, int);
		len += ft_intohex(s, "0123456789ABCDEF");
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int	printed_len;
	int	i;
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
	return (printed_len);
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
	ft_printf("My name is %s. My char is %c\n", string, singlechar);
	ft_printf("Address of num: %p\n", (void *)&num);
	ft_printf("Decimal Base 10 number: %d\n", num);
	ft_printf("Unsigned Int Decimal Base 10 number: %u\n", num1);
	ft_printf("Print unsigned int number in lowercase hex format: %x\n", num1);
	ft_printf("Print unsigned int number in uppercase hex format: %X\n", num1);
	return (0);
}
