/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:30:40 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:30:40 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(char *ligne, t_game *g)
{
	int	j;

	j = 0;
	while (ligne[j])
	{
		if (ligne[j] == 'C')
			g->t++;
		j++;
	}
	return (g->t);
}

void	collectible(t_game *g, int x, int y)
{
	if (g->l / 64 == x && g->h / 64 == y)
	{
		g->t--;
		mlx_put_image_to_window(g->mlx, g->win, g->is, x * 64, y * 64);
		g->map[y][x] = '0';
	}
	else
		mlx_put_image_to_window(g->mlx, g->win, g->ii, x * 64, y * 64);
	if (g->t == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->ie, \
g->pxe * 64, g->pye * 64);
}
