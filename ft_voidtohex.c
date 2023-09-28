/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidtohex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:58:41 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 11:58:41 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_voidtohex(void *p)
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