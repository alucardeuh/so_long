/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backgrounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:06:24 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:06:24 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void	draw_background3(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	free_niveau(g);
	images_niv_3(g);
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->im, x * 64, y * 64);
			else if (g->map[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->is, x * 64, y * 64);
			else if (g->map[y][x] == 'C')
				collectible(g, x, y);
			if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->is, x * 64, y * 64);
			else if (g->map[y][x] == 'P')
				find_pos_p(g, x, y);
			x++;
		}
		y++;
	}
}

void	draw_background2(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	free_niveau(g);
	images_niv_2(g);
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->im, x * 64, y * 64);
			else if (g->map[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->is, x * 64, y * 64);
			else if (g->map[y][x] == 'C')
				collectible(g, x, y);
			if (g->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->is, x * 64, y * 64);
			else if (g->map[y][x] == 'P')
				find_pos_p(g, x, y);
			x++;
		}
		y++;
	}
}

void	draw_background(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->im, x * 64, y * 64);
			else if (g->map[y][x] == 'T')
				mlx_put_image_to_window(g->mlx, g->win, g->im, x * 64, y * 64);
			else if (g->map[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->is, x * 64, y * 64);
			else if (g->map[y][x] == 'C')
				collectible(g, x, y);
			call_exit(g, x, y);
			if (g->map[y][x] == 'P')
				find_pos_p(g, x, y);
			x++;
		}
		y++;
	}
}

void	charger_images(t_game *g)
{
	g->im = mlx_xpm_file_to_image(g->mlx, "images/mur.xpm", &g->iw, &g->ih);
	g->is = mlx_xpm_file_to_image(g->mlx, "images/sol.xpm", &g->iw, &g->ih);
	g->ii = mlx_xpm_file_to_image(g->mlx, "images/item.xpm", &g->iw, &g->ih);
	g->ie = mlx_xpm_file_to_image(g->mlx, "images/exit.xpm", &g->iw, &g->ih);
	g->ij = mlx_xpm_file_to_image(g->mlx, "images/jn.xpm", &g->iw, &g->ih);
}
