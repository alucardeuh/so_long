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
  		printf("Erreur initialisation MLX\n");
		free_map(game->map);
		free(game);
		return (1);
	}
	return (0);
}

int	count_horizontale(char **map)
{
	int		i;

	i = 0;
	while (map[0][i] != '\n' && map[0][i] != '\0')
		i++;
	/*free(map[0]);*/
	return (i);
}

int	count_verticale(char **map)
{
	int		x;

	x = 0;
	while (map[x])
	{
		x++;
		/*free(map[--x]);  pas sur mais tu connais brr brbrrbrr grrr pawwwwww !!!!*/
	}
	return (x);
}

int	verif_map_c(char **map)
{
	int	y;
	int	count;
	int	x;

	count = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			x++;
			if (map[y][x] == 'C')
				count++;
		}
		/*free(map[y]);*/
		y++;
	}
	if (count <= 0)
	{
		printf("Erreur no exit");
		return (1);	
	}
	return (0);
}

int	verif_map_e(char **map)
{
	int	y;
	int	count;
	int	x;

	count = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			x++;
			if (map[y][x] == 'E')
				count++;
		}
		/*free(map[y]);*/
		y++;
	}
	if (count != 1)
	{
		printf("Erreur no exit");
		return (1);	
	}
	return (0);
}

int	verif_walls_cote(char **map) /*verif les wall sur le teco*/
{
	int	y;
	int	x;

	x = count_horizontale(map) - 1;
	y = 0;
	while (map[y])
	{
		if (map[y++][0] != '1' || map[y++][x] != '1')
			return (1);
		/*free(map[y]);*/
	}
	return (0);
}

int	verif_walls_haut(char **map) /*verif les wall sur le teco*/
{
	int	y;
	int	x;

	y = count_verticale(map) - 1;
	x = 0;
	while (map[0][x] == '1')
		x++;
	if (x != count_horizontale(map))
		return (1);
	x = 0;
	while (map[y][x] == '1')
		x++;
	if (x != count_horizontale(map))
		return (1);
	return (0);
}

int	verif_rectangle(char **map)
{
	int	i;
	int	o;

	i = count_verticale(map);
	o = count_horizontale(map);
	if (i == o)
	{
		printf("map pas rectangle gros !");
		return (1);	
	}
	return (0);
}

int	verif_name(t_game *game)
{
	int	i;
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
	return (0);
}
