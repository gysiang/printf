/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:55:47 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/29 12:11:27 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_int_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
