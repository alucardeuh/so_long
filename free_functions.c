/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:05:13 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:05:13 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, t_game *game)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < game->hm)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_niveau(t_game *g)
{
	if (g->im)
		mlx_destroy_image(g->mlx, g->im);
	if (g->is)
		mlx_destroy_image(g->mlx, g->is);
	if (g->ii)
		mlx_destroy_image(g->mlx, g->ii);
	if (g->ie)
		mlx_destroy_image(g->mlx, g->ie);
	if (g->ij)
		mlx_destroy_image(g->mlx, g->ij);
}
