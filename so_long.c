/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkarst <pkarst@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:46:14 by amalolla          #+#    #+#             */
/*   Updated: 2025/04/18 15:33:40 by pkarst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>
#include "get_next_line/get_next_line.h"

int	count_collectible(char *ligne, t_game *game)
{
	int	j;

	j = 0;
	while (ligne[j])
	{
		if (ligne[j] == 'C')
			game->t++;
		j++;
	}
	return (game->t);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < game->hauteur_map)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_char_map(char *filename)
{
	int		fd;
	int		i;
	char	*line;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] != '\n')
				count++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	read_map_lines(int fd, char **map, t_game *game)
{
	int		i;
	char	*ligne;

	i = 0;
	ligne = get_next_line(fd);
	if (!ligne)
	{
		free(map);
		close(fd);
	}
	game->largeur_map = ft_strlen(ligne) - 1;
	while (ligne)
	{
		map[i] = ligne;
		i++;
		count_collectible(ligne, game);
		ligne = get_next_line(fd);
	}
	map[i] = NULL;
	game->hauteur_map = i;
	close(fd);
}

char	**charger_carte(char *carte, t_game *game)
{
	int		count;
	int		fd;
	char	**map;

	count = count_char_map(carte);
	if (count <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (count));
	if (!map)
		return (NULL);
	fd = open(carte, O_RDONLY);
	if (fd < 0)
	{
		free_map(map, game);
		return (NULL);
	}
	read_map_lines(fd, map, game);
	close(fd);
	return (map);
}

int	quitter(t_game *game)
{
	free_niveau(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
	{
		free_map(game->map, game);
		game->map = NULL;
	}
	free(game);
	exit(0);
	return (0);
}

void	collectible(t_game *game, int x, int y)
{
	if (game->l / 64 == x && game->h / 64 == y)
	{
		game->t--;
		mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
		game->map[y][x] = '0';
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_item, x * 64, y * 64);
	if (game->t == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, game->pos_x_exit * 64, game->pos_y_exit * 64);
}

void	passer_niv_suivant(t_game *game)
{
	int	y;
	int	x;

	free_niveau(game);
	find_level(game);
	game->t = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
			{
				if ((x + y*y + game->level) % 5 == 0)
				{
					game->map[y][x] = 'C';
					game->t++;
				}
			}
			x++;
		}
		y++;
	}
	printf("%p\n", &x);
}

void	call_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')	
	{
		game->pos_x_exit = x;
		game->pos_y_exit = y;
		if (game->t == 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y * 64);
			if (game->map[game->h / 64][x] == game->map[y][x] && game->map[y][game->l / 64] == game->map[y][x] && ++game->level < 3)
			{
				if (game->level == 1)
					draw_background2(game);
				else
					draw_background3(game);
				passer_niv_suivant(game);
			}
			else if (game->level >= 3)
				quitter(game);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
	}
}

void	find_pos_p(t_game *game, int x, int y)
{
	game->pos_x = x * 64;
	game->pos_y = y * 64;
	mlx_put_image_to_window(game->mlx, game->win, game->img_joueur, game->pos_x, game->pos_y);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_mur, x * 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				collectible(game, x, y);
			call_exit(game, x, y);
			if (game->map[y][x] == 'P')
				find_pos_p(game, x, y);
			x++;
		}
		y++;
	}
}

void	charger_images(t_game *game)
{
	game->img_mur = mlx_xpm_file_to_image(game->mlx, "images/mur.xpm", &game->img_w, &game->img_h);
	game->img_sol = mlx_xpm_file_to_image(game->mlx, "images/sol.xpm", &game->img_w, &game->img_h);
	game->img_item = mlx_xpm_file_to_image(game->mlx, "images/item.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &game->img_w, &game->img_h);
	game->img_joueur = mlx_xpm_file_to_image(game->mlx, "images/joueur.xpm", &game->img_w, &game->img_h);
}

int	handle_key(int keycode, void *param)
{
	t_game	*game = (t_game *)param;
	game->h = game->pos_y;
	game->l = game->pos_x;
	if (keycode == XK_Escape)
		quitter(game);
	else if (keycode == XK_w && (game->map[game->pos_y / 64 - 1][game->pos_x / 64] != '1'))
	game->h = game->h - 64;
	else if (keycode == XK_s && (game->map[game->pos_y / 64 + 1][game->pos_x / 64] != '1'))
	game->h = game->h + 64;
	else if (keycode == XK_a && (game->map[game->pos_y / 64][game->pos_x / 64 - 1] != '1'))
	game->l = game->l - 64;
	else if (keycode == XK_d && (game->map[game->pos_y / 64][game->pos_x / 64 + 1] != '1'))
	game->l = game->l + 64;
	mlx_clear_window(game->mlx, game->win);
	if (game->pos_y != game->h || game->pos_x != game->l)
		printf("total mouv : %d\n", ++game->move);
	draw_background(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_sol, game->pos_x, game->pos_y);
	mlx_put_image_to_window(game->mlx, game->win, game->img_joueur, game->l, game->h);
	game->pos_y = game->h;
	game->pos_x = game->l;
	return (0);
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || map_presente(argv[1]) == 1)
	{
		printf("ERREUR ARG GROS (ou map)");
		return (1);
	}
	game = malloc(sizeof(t_game));
	init_var(game);
	if (!game)
		return (1);
	game->mlx = mlx_init();
	game->map = charger_carte(argv[1], game);
	if (!game->mlx || !game->map)
		erreur_init(game);
	if (appel_verif(game, argv[1]) == 1)
		return (0);
	game->win = mlx_new_window(game->mlx, game->largeur_map * 64, game->hauteur_map * 64, "so_long");
	charger_images(game);
	draw_background(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, quitter, game);
	mlx_loop(game->mlx);
	free(game);
	return (0);
}
