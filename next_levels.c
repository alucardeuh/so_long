/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_levels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:39:46 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:39:46 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_niv_3(t_game *g)
{
	g->is = mlx_xpm_file_to_image(g->mlx, "image3/sol.xpm", &g->iw, &g->ih);
	g->ii = mlx_xpm_file_to_image(g->mlx, "image3/item.xpm", &g->iw, &g->ih);
	g->im = mlx_xpm_file_to_image(g->mlx, "image3/mur.xpm", &g->iw, &g->ih);
	g->ie = mlx_xpm_file_to_image(g->mlx, "image3/exit.xpm", &g->iw, &g->ih);
	g->ij = mlx_xpm_file_to_image(g->mlx, "image3/jn.xpm", &g->iw, &g->ih);
}

void	images_niv_2(t_game *g)
{
	g->is = mlx_xpm_file_to_image(g->mlx, "image2/sol.xpm", &g->iw, &g->ih);
	g->ii = mlx_xpm_file_to_image(g->mlx, "image2/item.xpm", &g->iw, &g->ih);
	g->im = mlx_xpm_file_to_image(g->mlx, "image2/mur.xpm", &g->iw, &g->ih);
	g->ie = mlx_xpm_file_to_image(g->mlx, "image2/exit.xpm", &g->iw, &g->ih);
	g->ij = mlx_xpm_file_to_image(g->mlx, "image2/jn.xpm", &g->iw, &g->ih);
}

void	find_level(t_game *g)
{
	if (g->lv == 1)
		images_niv_2(g);
	else if (g->lv == 2)
		images_niv_3(g);
}

void	passer_niv_suivant(t_game *g)
{
	int	y;
	int	x;

	free_niveau(g);
	find_level(g);
	g->t = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '0')
			{
				if ((x + y * y + g->lv) % 5 == 0)
				{
					g->map[y][x] = 'C';
					g->t++;
				}
			}
			x++;
		}
		y++;
	}
}
