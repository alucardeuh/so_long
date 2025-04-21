/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:09:49 by amalolla          #+#    #+#             */
/*   Updated: 2025/02/10 10:09:49 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_print_putchar(int a);
int		ft_print_putstr(char *str);
int		ft_print_dec(int nb);
int		ft_print_unsigned(unsigned int c);
int		ft_print_hex_l(unsigned int a);
int		ft_print_hex_u(unsigned int b);
int		ft_print_ptr(unsigned long n);
int		ft_printf(const char *str, ...);
int		ft_print_pourcent(void);
char	*ft_itoa(int n);
char	*ft_strdup(const	char *s1);

#endif
