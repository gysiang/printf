/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:56:29 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 15:56:46 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_positive(int n, int fd)
{
	int	len;

	len = 0;
	if (n / 10)
	len += print_positive(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
	return (len + 1);
}
int ft_int_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (print_positive(-n, fd) + 1);
	}
	return (print_positive(n, fd));
}
