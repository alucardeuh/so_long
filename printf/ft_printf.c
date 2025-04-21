/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:08:58 by amalolla          #+#    #+#             */
/*   Updated: 2025/02/10 10:08:59 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_putchar(va_arg(*args, int));
	else if (format == 's')
		len += ft_print_putstr(va_arg(*args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(*args, unsigned long long));
	else if (format == 'd')
		len += ft_print_dec(va_arg(*args, int));
	else if (format == 'i')
		len += ft_print_dec(va_arg(*args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x')
		len += ft_print_hex_l(va_arg(*args, unsigned int));
	else if (format == 'X')
		len += ft_print_hex_u(va_arg(*args, unsigned int));
	else if (format == '%')
		len += ft_print_pourcent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(&args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
