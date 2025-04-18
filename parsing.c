/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:16:14 by amalolla          #+#    #+#             */
/*   Updated: 2025/04/12 16:16:15 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_game *game)
{
	game->move = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->h = 0;
	game->l = 0;
	game->t = 0;
	game->pos_x_exit = 0;
	game->pos_y_exit = 0;
	game->img_mur = NULL;
	game->img_sol = NULL;
	game->img_item = NULL;
	game->img_exit = NULL;
	game->img_joueur = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
}

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
		free_map(game->map);
		free(game);
		return (1);
	}
	return (0);
}

int	verif_walls_cote(t_game *game)
{
	int	y;
	int	x;

	x = game->largeur_map - 1;
	y = 0;
	while (y < game->hauteur_map)
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
		while (x < game->largeur_map)
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
		while (x < game->largeur_map)
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
		while (x < game->largeur_map)
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
	return (0);
}

int	verif_walls_haut(t_game *game)
{
	int	y;
	int	x;

	y = game->hauteur_map - 1;
	x = 0;
	while (game->map[0][x] == '1')
		x++;
	if (x != game->largeur_map)
	{
		printf("%s", "Probleme de mur horizontal");
		return (1);
	}
	x = 0;
	while (game->map[y][x] == '1')
		x++;
	if (x != game->largeur_map)
	{
		printf("%s", "Probleme de mur horizontal");
		return (1);
	}
	return (0);
}

int	verif_rectangle(t_game *game)
{
	int	i;
	int	o;

	i = game->hauteur_map;
	o = game->largeur_map;
	if (i == o)
	{
		printf("map pas rectangulaire gros !");
		return (1);
	}
	return (0);
}

int	verif_name(t_game *game)
{
	int		i;
	char	*str;

	str = game->argv1;
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

int	verif_all(t_game *game)
{
	if (verif_name(game) == 1)
		return (1);
	if (verif_rectangle(game) == 1)
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
