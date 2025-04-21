/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:29:45 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:29:45 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

int	handle_key(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	g->h = g->py;
	g->l = g->px;
	if (keycode == XK_Escape)
		quitter(g);
	else if (keycode == XK_w && (g->map[g->py / 64 - 1][g->px / 64] != '1'))
		g->h = g->h - 64;
	else if (keycode == XK_s && (g->map[g->py / 64 + 1][g->px / 64] != '1'))
		g->h = g->h + 64;
	else if (keycode == XK_a && (g->map[g->py / 64][g->px / 64 - 1] != '1'))
		g->l = g->l - 64;
	else if (keycode == XK_d && (g->map[g->py / 64][g->px / 64 + 1] != '1'))
		g->l = g->l + 64;
	mlx_clear_window(g->mlx, g->win);
	if (g->py != g->h || g->px != g->l)
		put_count(g);
	draw_background(g);
	find_image_directions(keycode, g);
	mlx_put_image_to_window(g->mlx, g->win, g->is, g->px, g->py);
	mlx_put_image_to_window(g->mlx, g->win, g->ij, g->l, g->h);
	g->py = g->h;
	g->px = g->l;
	return (0);
}
