/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyong-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:36:36 by gyong-si          #+#    #+#             */
/*   Updated: 2023/09/29 18:31:57 by gyong-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	negative_int;
	int	x;
	int	y;
	char	z;
	unsigned int	unsigned_int;
	
	x = 42;
	y = -42;
	z = 'g';
	negative_int = -42;
	unsigned_int = 4294967295;
	printf("Test 1 -a: %d\n", 42);
	ft_printf("Test 1 -b: %d\n", 42);
	printf("Test 2 -a: %s\n", "Hello World");
	ft_printf("Test 2 -b: %s\n", "Hello World");
	printf("Test 3 -a: %c\n", 'A');
	ft_printf("Test 3 -b: %c\n", 'A');
	printf("Test 4 -a: %%\n");
	ft_printf("Test 4 -b: %%\n");
	printf("Test 5 -a: %u\n", 12345);
	ft_printf("Test 5 -b: %u\n", 12345);
	printf("Test 6 -a: %x\n", 255);
	ft_printf("Test 6 -b: %x\n", 255);
	printf("Test 7 -a: %X\n", 255);
	ft_printf("Test 7 -b: %X\n", 255);
	printf("Test 8 -a: %d\n", negative_int);
	ft_printf("Test 8 -b: %d\n", negative_int);
	printf("Test 9 -a: %u\n", unsigned_int);
	ft_printf("Test 9 -b: %u\n", unsigned_int);
	printf("Test 10 -a: %p\n", &x);
	ft_printf("Test 10 -b: %p\n", &x);
	printf("Test 11 -a: %p\n", &y);
	ft_printf("Test 11 -b: %p\n", &y);
	printf("Test 12 -a: %p\n", &z);
	ft_printf("Test 12 -b: %p\n", &z);
	return (0);
}
