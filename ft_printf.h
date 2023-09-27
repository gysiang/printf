/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:28:51 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/28 00:29:18 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

int ft_printf(const char *s, ...);
static int ft_int_putchar_fd(char c, int fd);
static int ft_int_putstr_fd(char *s, int fd);
static int ft_int_putnbr_fd(int n, int fd);
static int ft_putnbr_unsigned(unsigned int n);
static int ft_numlen(int num);
static int ft_voidtohex(void *p);
static int ft_intohex(unsigned int s, char *base);

#endif
