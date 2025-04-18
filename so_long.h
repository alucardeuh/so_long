/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkarst <pkarst@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:34:43 by amalolla          #+#    #+#             */
/*   Updated: 2025/04/18 15:18:51 by pkarst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char	**map;
	void		*img_mur;
	void		*img_sol;
	void		*img_item;
	void		*img_exit;
	void		*img_joueur;
	char		*argv1;
	int			img_w;
	int			img_h;
	int			largeur_map;
	int			hauteur_map;
	int			pos_x;
	int			pos_y;
	int			move;
	int			h;
	int			l;
	int			t;
	int			pos_x_exit;
	int			pos_y_exit;
} t_game;

void	read_map_lines(int fd, char **map, t_game *game);
int	count_collectible(char *ligne, t_game *game);
void	collectible(t_game *game, int x, int y);
char	**charger_carte(char *carte, t_game *game);
void	free_map(char **map, t_game *game);
int	quitter(t_game *game);
int	quitter_2(t_game *game);
void	charger_images(t_game *game);
int	handle_key(int keycode, void *param);
void	draw_background(t_game *game);
int	erreur_init(t_game *game);
void	init_var(t_game *game);
int	count_char_map(char *filename);
int	verif_map_c(t_game *game);
int	verif_map_e(t_game *game);
int	verif_walls_cote(t_game *game);
int	verif_walls_haut(t_game *game);
int	verif_rectangle(t_game *game);
int	verif_name(t_game *game);
int	verif_all(t_game *game);
int	verif_taille_lignes(t_game *game);
int	verif_chemin(t_game *game);
void	flood_fill(char **map_copy, int x, int y);
int	loc_y_e(t_game *game);
int	loc_x_e(t_game *game);
int	loc_y_p(t_game *game);
int	loc_x_p(t_game *game);
//void	flood_fill2(t_game *game, int x, int y);
int	map_presente(char *carte);
int	compte_bien_gros(char **map_copy, t_game *game);
void	draw_background(t_game *game);

#endif
