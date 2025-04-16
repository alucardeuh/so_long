/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:46:14 by amalolla          #+#    #+#             */
/*   Updated: 2025/04/05 19:46:15 by amalolla         ###   ########.fr       */
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
	return(game->t);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}


int	count_char_map(const char *filename)
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

char	**alloc_map(int count)
{
	char **map;

	map = malloc(sizeof(char *) * (count));
	return (map);
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
	map = alloc_map(count);
	if (!map)
		return (NULL);
	fd = open(carte, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		return (NULL);
	}
	read_map_lines(fd, map, game);
	close(fd);
	return (map);
}


/*char	**charger_carte(char *carte, t_game *game)
{
	int			i;
	int			count;
	int			fd;
	char	**map;
	char		*ligne;

	i = 0;
	count = count_char_map(carte);
	map = malloc(sizeof(char*) * (count));
	fd = open(carte, O_RDONLY);
	ligne = get_next_line(fd);
	if (fd < 0 || !map)
		return NULL;
	if (!ligne)
	{
		free(map);
		close(fd);
		return NULL;
	}
	game->largeur_map = strlen(ligne) - 1;
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
	return (map);
}*/

int	quitter(t_game *game)
{
	if (game->img_mur)
		mlx_destroy_image(game->mlx, game->img_mur);
	if (game->img_sol)
		mlx_destroy_image(game->mlx, game->img_sol);
	if (game->img_item)
		mlx_destroy_image(game->mlx, game->img_item);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_joueur)
		mlx_destroy_image(game->mlx, game->img_joueur);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
	{
		free_map(game->map);
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
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, game->pos_x_exit * 64, game->pos_y_exit * 64); /* sinon l image exit apparait apres avoir reappuye sur une touche */
}

/*void	passer_niv_suivant(t_game *game)
{
	int	y;

	game->level++;
	game->img_sol = mlx_xpm_file_to_image(game->mlx, "image/sol.xpm", &game->img_w, &game->img_h);
	game->img_item = mlx_xpm_file_to_image(game->mlx, "image/item.xpm", &game->img_w, &game->img_h);
	game->img_mur = mlx_xpm_file_to_image(game->mlx, "image/mur.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "image/exit.xpm", &game->img_w, &game->img_h);
	game->t = 0;
	y = 0;
	while (game->map[y])
	{
		int x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
			{
				if ((x + y + game->level) % 5 == 0)
				{
					game->map[y][x] = 'C';
					game->t++;
				}
			}
			x++;
		}
		y++;
	}
}*/

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
			if (game->map[y][x] == 'E')	
			{
				game->pos_x_exit = x;
				game->pos_y_exit = y;
				if (game->t == 0)  /* apres avoir pris tous les collectibles, t = 0 car c est une volatile int */
				{
					mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y * 64);
					if (game->map[game->h / 64][x] == game->map[y][x] && game->map[y][game->l / 64] == game->map[y][x])
						quitter(game);
						/*passer_niv_suivant(game);*/
				}
				else
					mlx_put_image_to_window(game->mlx, game->win, game->img_sol, x * 64, y * 64);
			}
			else if (game->map[y][x] == 'P')
			{
				game->pos_x = x * 64;
				game->pos_y = y * 64;
				mlx_put_image_to_window(game->mlx, game->win, game->img_joueur, game->pos_x, game->pos_y);
			}
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
	else if (keycode == XK_w && (game->map[game->pos_y / 64 - 1][game->pos_x / 64] != '1')) /*si la map a l index [game->pos_y / 64 - 1][game->pos_x / 64] est differnet de 1 qui correspon a un mur*/
		game->h = game->h - 64;
	else if (keycode == XK_s && (game->map[game->pos_y / 64 + 1][game->pos_x / 64] != '1')) /* et on divise par 64 car c est l index et non les bits*/
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
	if (argc != 2)
	{
		printf("ERREUR ARG GROS != 2");
		return (1);
	}
	t_game *game = malloc(sizeof(t_game));
	init_var(game);
	game->argv1 = argv[1];
	if (!game)
		return (1);
	game->mlx = mlx_init();
	game->map = charger_carte(argv[1], game);
	if (!game->mlx || !game->map)
		erreur_init(game);
	if (verif_all(game) == 1)
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
