/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:04:00 by amalolla          #+#    #+#             */
/*   Updated: 2025/04/17 17:04:01 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	loc_x_p(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->largeur_map)
		{
			x++;
			if (game->map[y][x] == 'P')
				return (x);
		}
		y++;
	}
	return (0);
}

int	loc_y_p(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->largeur_map)
		{
			x++;
			if (game->map[y][x] == 'P')
				return (y);
		}
		y++;
	}
	return (0);
}

int	loc_x_e(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->largeur_map)
		{
			x++;
			if (game->map[y][x] == 'E')
				return (x);
		}
		y++;
	}
	return (0);
}

int	loc_y_e(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->largeur_map)
		{
			x++;
			if (game->map[y][x] == 'E')
				return (y);
		}
		y++;
	}
	return (0);
}

int	count_coll(t_game *game)
{
	int	y;
	int	count;
	int	x;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->largeur_map)
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	flood_fill2(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;

	if (game->map[y][x] == 'R')
		game->map[y][x] = 'C';
	else if (game->map[y][x] == 'L')
		game->map[y][x] = '0';
	else
		return ;
	game->map[y][x] = '0';
	flood_fill2(game, x + 1, y);
	flood_fill2(game, x - 1, y);
	flood_fill2(game, x, y + 1);
	flood_fill2(game, x, y - 1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'L' || game->map[y][x] == 'R')
		return ;
	if (game->map[y][x] == 'C')
		game->map[y][x] = 'R';
	else
		game->map[y][x] = 'L';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

int	compte_bien_gros(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->largeur_map)
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	verif_chemin(t_game *game)
{
	int	x;
	int	y;
	int	x2;
	int	y2;
	int	count;

	x2 = loc_x_e(game);
	y2 = loc_y_e(game);
	x = loc_x_p(game);
	y = loc_y_p(game);
	flood_fill(game, x, y);
	count = compte_bien_gros(game);
	if (game->map[y2][x2] != 'L' || count != 0)
	{
		printf("NO CHEMIN");
		return (1);
	}
	flood_fill2(game, x, y);
	game->map[y][x] = 'P';
	game->map[y2][x2] = 'E';
	return (0);
}
