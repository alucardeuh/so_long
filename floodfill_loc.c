/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_loc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 20:22:48 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 20:22:48 by amalolla         ###   ########.fr       */
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
		while (x < game->lm)
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
		while (x < game->lm)
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
		while (x < game->lm)
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
		while (x < game->lm)
		{
			x++;
			if (game->map[y][x] == 'E')
				return (y);
		}
		y++;
	}
	return (0);
}
