/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 20:24:12 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 20:24:12 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		x;
	int		y;

	y = 0;
	while (y < game->hm)
	{
		x = 0;
		while (x < game->lm)
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
	int		x;
	int		y;
	int		x2;
	int		y2;
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
