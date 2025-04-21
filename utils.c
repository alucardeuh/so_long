/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:07:51 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:07:51 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_length(int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
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

char	*conversion(char *str, int r, int o)
{
	int	i;

	i = o - 1;
	while (r > 0)
	{
		str[i] = r % 10 + '0';
		r = r / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	int		o;

	o = ft_length(n);
	if (n == 0)
		return (ft_strdup("0"));
	new_str = malloc((o + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	conversion(new_str, n, o);
	new_str[o] = '\0';
	return (new_str);
}

void	find_pos_p(t_game *g, int x, int y)
{
	char	*str;

	str = ft_itoa(g->m);
	if (str == NULL)
		return ;
	if (g->py != g->h || g->px != g->l)
		put_count(g);
	else
	{
		mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, "Moves:");
		mlx_string_put(g->mlx, g->win, 70, 10, 0xFFA500, str);
	}
	g->px = x * 64;
	g->py = y * 64;
	mlx_put_image_to_window(g->mlx, g->win, g->ij, g->px, g->py);
	if (g->m != 0)
		mlx_put_image_to_window(g->mlx, g->win, g->is, g->px, g->py);
	free(str);
}

void	put_count(t_game *game)
{
	char	*str;

	game->m++;
	str = ft_itoa(game->m);
	if (str == NULL)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moves:");
	mlx_string_put(game->mlx, game->win, 70, 10, 0xFFA500, str);
	free(str);
}
