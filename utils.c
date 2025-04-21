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

void	find_pos_p(t_game *game, int x, int y)
{
	game->px = x * 64;
	game->py = y * 64;
	mlx_put_image_to_window(game->mlx, game->win, game->ij, game->px, game->py);
	if (game->m != 0)
		mlx_put_image_to_window(game->mlx, game->win, game->is, game->px, game->py);
}

void	put_count(t_game *game)
{
	char	*str;

	game->m++;
	str = ft_itoa(game->m);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moves:");
	mlx_string_put(game->mlx, game->win, 70, 10, 0xFFA500, str);
	free(str);
}
