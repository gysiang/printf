/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <gyongsi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:11:08 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/25 15:57:27 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int num_args;
	int	printed_len;
	int	i;
	va_list	args;

	i = 0;
	printed_len = 0;
	num_args = ft_strlen(s);
	va_start(args, s);
	while (i < num_args && s[i] != '\0')
	{
		if (s[i] == ' ')
		{
			i++;
			printed_len++;
		}
		if (s[i] == '%')
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
	char *string;

	singlechar = 'h';
	string = "hello";
	ft_printf("%c", singlechar);
	write(1, "\n", 1);
	ft_printf("%s", string);
	return (0);
}
