/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:39:30 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:39:30 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2 || map_presente(argv[1]) == 1)
	{
		printf("ERREUR ARG GROS (ou map)");
		return (1);
	}
	g = malloc(sizeof(t_game));
	init_var(g);
	if (!g)
		return (1);
	g->mlx = mlx_init();
	g->map = charger_carte(argv[1], g);
	if (!g->mlx || !g->map)
		erreur_init(g);
	if (appel_verif(g, argv[1]) == 1)
		return (0);
	g->win = mlx_new_window(g->mlx, g->lm * 64, g->hm * 64, "so_long");
	charger_images(g);
	draw_background(g);
	mlx_put_image_to_window(g->mlx, g->win, g->ij, g->px, g->py);
	mlx_hook(g->win, 2, 1L << 0, handle_key, g);
	mlx_hook(g->win, 17, 0, quitter, g);
	mlx_loop(g->mlx);
	free(g);
	return (0);
}
