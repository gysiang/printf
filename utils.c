/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:24:35 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 00:25:43 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_int_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int ft_int_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

static int ft_int_putnbr_fd(int n, int fd)
{
	int s;

	s = n;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return;
		}
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
	if (s > 0)
		return (ft_numlen(s));
	else
		return (ft_numlen(s + 1));
}

static int ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
	return (ft_numlen(n));
}

static int ft_numlen(int num)
{
	int len;

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
	int i;
	int len;
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
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(&hex[i], 1);
	return (len);
}

static int ft_intohex(unsigned int s, char *base)
{
	unsigned int c;
	int i;
	int len;
	char hex[16];

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
	ft_putstr_fd(&hex[i + 1], 1);
	return (len);
}
