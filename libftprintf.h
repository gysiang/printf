/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:28:51 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 16:00:49 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

int ft_printf(const char *s, ...);
int ft_int_putchar_fd(char c, int fd);
int ft_int_putstr_fd(char *s, int fd);
int ft_int_putnbr_fd(int n, int fd);
int ft_numlen(int num);
int ft_voidtohex(void *p);
int ft_intohex(unsigned int s, char *base);

#endif
