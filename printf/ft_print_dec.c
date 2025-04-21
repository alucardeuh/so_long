/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:00:57 by amalolla          #+#    #+#             */
/*   Updated: 2025/02/10 10:00:59 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a == -2147483648)
	{
		return (11);
	}
	if (a < 0)
	{
		a = -a;
		i++;
	}
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

int	ft_print_dec(int nb)
{
	char	*str;
	int		i;

	str = ft_itoa(nb);
	i = 0;
	while (str[i] != '\0')
	{
		ft_print_putchar(str[i]);
		i++;
	}
	free(str);
	return (ft_length(nb));
}
