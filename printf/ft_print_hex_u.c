/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:02:54 by amalolla          #+#    #+#             */
/*   Updated: 2025/02/10 10:02:55 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_length_hex(unsigned int c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c = c / 16;
		i++;
	}
	return (i);
}

void	ft_convert_hex_u(unsigned int b)
{
	if (b >= 16)
	{
		ft_convert_hex_u(b / 16);
		ft_convert_hex_u(b % 16);
	}
	else
	{
		if (b <= 9)
			ft_print_unsigned(b);
		else
		{
			ft_print_putchar((b - 10 + 'A'));
		}
	}
}

int	ft_print_hex_u(unsigned int b)
{
	ft_convert_hex_u(b);
	return (ft_length_hex(b));
}
