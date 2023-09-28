/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:59:07 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 12:37:15 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_intohex(unsigned int s, char *base)
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
