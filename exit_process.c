/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:32:58 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:32:58 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quitter(t_game *g)
{
	free_niveau(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	if (g->map)
	{
		free_map(g->map, g);
		g->map = NULL;
	}
	free(g);
	exit(0);
	return (0);
}

void	call_exit(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'E')
	{
		g->pxe = x;
		g->pye = y;
		if (g->t == 0)
		{
			mlx_put_image_to_window(g->mlx, g->win, g->ie, x * 64, y * 64);
			if (g->map[g->h / 64][x] == g->map[y][x] && g->map[y][g->l / 64] \
== g->map[y][x] && ++g->lv < 3)
			{
				if (g->lv == 1)
					draw_background2(g);
				else
					draw_background3(g);
				passer_niv_suivant(g);
			}
			else if (g->lv >= 3)
				quitter(g);
		}
		else
			mlx_put_image_to_window(g->mlx, g->win, g->is, x * 64, y * 64);
	}
}
