/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niveau2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:25:20 by amalolla          #+#    #+#             */
/*   Updated: 2025/04/18 18:25:21 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_niveau(t_game *game)
{
	if (game->img_mur)
		mlx_destroy_image(game->mlx, game->img_mur);
	if (game->img_sol)
		mlx_destroy_image(game->mlx, game->img_sol);
	if (game->img_item)
		mlx_destroy_image(game->mlx, game->img_item);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_joueur)
		mlx_destroy_image(game->mlx, game->img_joueur);
}

void	images_niv_3(t_game *game)
{
	game->img_sol = mlx_xpm_file_to_image(game->mlx, "image3/sol.xpm", &game->img_w, &game->img_h);
	game->img_item = mlx_xpm_file_to_image(game->mlx, "image3/item.xpm", &game->img_w, &game->img_h);
	game->img_mur = mlx_xpm_file_to_image(game->mlx, "image3/mur.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "image3/exit.xpm", &game->img_w, &game->img_h);
	game->img_joueur = mlx_xpm_file_to_image(game->mlx, "image3/joueur.xpm", &game->img_w, &game->img_h);
}


void	images_niv_2(t_game *game)
{
	game->img_sol = mlx_xpm_file_to_image(game->mlx, "image2/sol.xpm", &game->img_w, &game->img_h);
	game->img_item = mlx_xpm_file_to_image(game->mlx, "image2/item.xpm", &game->img_w, &game->img_h);
	game->img_mur = mlx_xpm_file_to_image(game->mlx, "image2/mur.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "image2/exit.xpm", &game->img_w, &game->img_h);
	game->img_joueur = mlx_xpm_file_to_image(game->mlx, "image2/joueur.xpm", &game->img_w, &game->img_h);
}

void	find_level(t_game *game)
{
	if (game->level == 1)
		images_niv_2(game);
	else if (game->level == 2)
		images_niv_3(game);
}

void	draw_background3(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	free_niveau(game);
	images_niv_3(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_mur, x * 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				collectible(game, x, y);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				find_pos_p(game, x, y);
			x++;
		}
		y++;
	}
}

void	draw_background2(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	free_niveau(game);
	images_niv_2(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_mur, x * 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				collectible(game, x, y);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				find_pos_p(game, x, y);
			x++;
		}
		y++;
	}
}
