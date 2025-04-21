/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:39:23 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:39:23 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_game *game)
{
	game->m = 0;
	game->px = 0;
	game->py = 0;
	game->h = 0;
	game->l = 0;
	game->t = 0;
	game->pxe = 0;
	game->pye = 0;
	game->im = NULL;
	game->is = NULL;
	game->ii = NULL;
	game->ie = NULL;
	game->ij = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->lv = 0;
}

int	appel_verif(t_game *game, char *str)
{
	if (verif_name(str) == 1)
	{
		quitter(game);
		return (1);
	}
	if (verif_all(game) == 1)
	{
		quitter(game);
		return (1);
	}
	return (0);
}

int	verif_all(t_game *game)
{
	if (bon_char(game) == 1)
		return (1);
	if (verif_walls_haut(game) == 1)
		return (1);
	if (verif_map_e(game) == 1)
		return (1);
	if (verif_map_c(game) == 1)
		return (1);
	if (verif_walls_cote(game) == 1)
		return (1);
	if (erreur_init(game) == 1)
		return (1);
	if (verif_taille_lignes(game) == 1)
		return (1);
	if (verif_chemin(game) == 1)
		return (1);
	return (0);
}
