/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:10:00 by mouad             #+#    #+#             */
/*   Updated: 2024/11/26 15:05:59 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_hex(int n)
{
	char	*hex_numbers;
	int		count;

	hex_numbers = "0123456789abcdef";
	count = 0;
	if (n == INT_MIN)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 16)
		count += ft_print_hex(n / 16);
	count += ft_putchar(hex_numbers[n % 16]);
	return (count);
}
