/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:35:03 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:35:03 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	erreur_init(t_game *game)
{
	if (!game->map)
	{
		printf("erreur chargement\n");
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
		return (1);
	}
	if (!game->mlx)
	{
		printf ("Erreur initialisation MLX\n");
		free_map(game->map, game);
		free(game);
		return (1);
	}
	return (0);
}

int	verif_name(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] != '.')
		return (1);
	i++;
	if (str[i] != 'b')
		return (1);
	i++;
	if (str[i] != 'e')
		return (1);
	i++;
	if (str[i] != 'r')
		return (1);
	if (str[++i])
		return (1);
	return (0);
}

int	map_presente(char *carte)
{
	int	fd;

	if (!carte)
	{
		printf("no map");
		return (1);
	}
	fd = open(carte, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

int	bon_char(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (x < game->lm - 1)
		{
			if (game->map[y][x] != 'P' && game->map[y][x] \
!= '0' && game->map[y][x] != 'C' && game->map[y][x] \
!= 'E' && game->map[y][x] != '1')
			{
				printf("PAS LES BON CHAR");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	verif_taille_lignes(t_game *game)
{
	int	y;
	int	taille;

	y = 0;
	taille = ft_strlen(game->map[0]);
	while (game->map[y])
	{
		if (taille != ft_strlen(game->map[y]))
		{
			printf("%s", "Pas la mm taille mgl");
			return (1);
		}
		y++;
	}
	if (game->hm == game->lm)
	{
		printf("map pas rectangulaire gros !");
		return (1);
	}
	return (0);
}
