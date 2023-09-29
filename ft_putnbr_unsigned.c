/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:24:52 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 22:25:11 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int i;

	printout(n);
	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
