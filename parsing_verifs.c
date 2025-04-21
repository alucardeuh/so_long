/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verifs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:38:59 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:38:59 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_walls_cote(t_game *game)
{
	int	y;
	int	x;

	x = game->lm - 1;
	y = 0;
	while (y < game->hm)
	{
		if (game->map[y][0] != '1' || game->map[y][x] != '1')
		{
			printf("probleme wall teco");
			return (1);
		}
		y++;
	}
	return (0);
}

int	verif_map_c(t_game *game)
{
	int	y;
	int	count;
	int	x;

	count = 0;
	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->lm)
		{
			x++;
			if (game->map[y][x] == 'C')
				count++;
		}
		y++;
	}
	if (count <= 0)
	{
		printf("Erreur no collectible gros!!");
		return (1);
	}
	return (0);
}

int	verif_map_e(t_game *game)
{
	int	y;
	int	count;
	int	x;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->lm)
		{
			x++;
			if (game->map[y][x] == 'E')
				count++;
		}
		y++;
	}
	if (count != 1)
	{
		printf ("Erreur exit");
		return (1);
	}
	return (0);
}

int	verif_map_p(t_game *game)
{
	int	y;
	int	count;
	int	x;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->lm)
		{
			x++;
			if (game->map[y][x] == 'P')
				count++;
		}
		y++;
	}
	if (count != 1)
	{
		printf("Erreur no player");
		return (1);
	}
	return (0);
}

int	verif_walls_haut(t_game *game)
{
	int	y;
	int	x;

	y = game->hm - 1;
	x = 0;
	while (game->map[0][x] == '1')
		x++;
	if (x != game->lm)
	{
		printf("%s", "Probleme de mur horizontal");
		return (1);
	}
	x = 0;
	while (game->map[y][x] == '1')
		x++;
	if (x != game->lm)
	{
		printf("%s", "Probleme de mur horizontal");
		return (1);
	}
	return (0);
}
