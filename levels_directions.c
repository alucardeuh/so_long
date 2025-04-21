/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 21:42:26 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 21:42:26 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void	find_image_directions(int keycode, t_game *game)
{
	if (game->lv == 0)
		image_directions_lv1(keycode, game);
	else if (game->lv == 1)
		image_directions_lv2(keycode, game);
	else if (game->lv == 2)
		image_directions_lv3(keycode, game);
}

void	image_directions_lv1(int keycode, t_game *g)
{
	if (keycode == XK_w)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "images/jn.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_s)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "images/js.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_a)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "images/ja.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_d)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "images/jd.xpm", &g->iw, &g->ih);
	}
}

void	image_directions_lv2(int keycode, t_game *g)
{
	if (keycode == XK_w)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image2/jn.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_s)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image2/js.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_a)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image2/ja.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_d)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image2/jd.xpm", &g->iw, &g->ih);
	}
}

void	image_directions_lv3(int keycode, t_game *g)
{
	if (keycode == XK_w)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image3/jn.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_s)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image3/js.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_a)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image3/ja.xpm", &g->iw, &g->ih);
	}
	else if (keycode == XK_d)
	{
		mlx_destroy_image(g->mlx, g->ij);
		g->ij = mlx_xpm_file_to_image(g->mlx, "image3/jd.xpm", &g->iw, &g->ih);
	}
}