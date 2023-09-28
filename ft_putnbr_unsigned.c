/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:57:33 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 11:58:37 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr_unsigned(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
	return (ft_numlen(n));
}
