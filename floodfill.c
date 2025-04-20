/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkarst <pkarst@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:04:00 by amalolla          #+#    #+#             */
/*   Updated: 2025/04/18 14:27:11 by pkarst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**new_char;
	int	count;
	int	i;
	int	j;

	count = game->hauteur_map * game->largeur_map;
	new_char = malloc(sizeof(char*) * (count));
	i = 0;
	while (i < game->hauteur_map)
	{
		new_char[i] = malloc(sizeof(char) * game->largeur_map);
		j = 0;
		while (j < game->largeur_map)
		{
			new_char[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	return (new_char);
}

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

void	flood_fill(char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'L' || map_copy[y][x] == 'R')
		return ;
	if (map_copy[y][x] == 'C')
		map_copy[y][x] = 'R';
	else
		map_copy[y][x] = 'L';
	flood_fill(map_copy, x + 1, y);
	flood_fill(map_copy, x - 1, y);
	flood_fill(map_copy, x, y + 1);
	flood_fill(map_copy, x, y - 1);
}

int	compte_bien_gros(char **map_copy, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->hauteur_map)
	{
		x = 0;
		while (x < game->largeur_map)
		{
			if (map_copy[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	verif_chemin(t_game *game)
{
	int	x;
	int	y;
	int	x2;
	int	y2;
	char	**map_copy;

	map_copy = copy_map(game);
	x2 = loc_x_e(game);
	y2 = loc_y_e(game);
	x = loc_x_p(game);
	y = loc_y_p(game);
	flood_fill(map_copy, x, y);
	if (map_copy[y2][x2] != 'L' || compte_bien_gros(map_copy, game) != 0)
	{
		free_map(map_copy, game);
		printf("NO CHEMIN");
		return (1);
	}
	free_map(map_copy, game);
	return (0);
}
