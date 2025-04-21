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

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*im;
	void		*is;
	void		*ii;
	void		*ie;
	void		*ij;
	int			ih;
	int			iw;
	int			lm;
	int			hm;
	int			px;
	int			py;
	int			m;
	int			h;
	int			l;
	int			t;
	int			pxe;
	int			pye;
	int			lv;
}	t_game;

int		ft_length(int a);
int		count_collectible(char *ligne, t_game *g);
int		quitter(t_game *g);
int		quitter_2(t_game *game);
int		handle_key(int keycode, void *param);
int		erreur_init(t_game *game);
int		count_char_map(char *filename);
int		verif_map_c(t_game *game);
int		verif_map_e(t_game *game);
int		verif_walls_cote(t_game *game);
int		verif_walls_haut(t_game *game);
int		verif_name(char *str);
int		verif_all(t_game *game);
int		verif_taille_lignes(t_game *game);
int		verif_chemin(t_game *game);
int		loc_y_e(t_game *game);
int		loc_x_e(t_game *game);
int		loc_y_p(t_game *game);
int		loc_x_p(t_game *game);
int		map_presente(char *carte);
int		compte_bien_gros(char **map_copy, t_game *game);
int		appel_verif(t_game *game, char *str);
int		bon_char(t_game *game);

char	*conversion(char *str, int r, int o);
char	*ft_itoa(int n);
char	**charger_carte(char *carte, t_game *game);
char	**copy_map(t_game *game);

void	put_count(t_game *game);
void	read_map_lines(int fd, char **map, t_game *game);
void	image_directions_lv1(int keycode, t_game *g);
void	image_directions_lv2(int keycode, t_game *g);
void	image_directions_lv3(int keycode, t_game *g);
void	find_image_directions(int keycode, t_game *game);
void	collectible(t_game *g, int x, int y);
void	free_map(char **map, t_game *game);
void	charger_images(t_game *g);
void	draw_background(t_game *game);
void	init_var(t_game *game);
void	flood_fill(char **map_copy, int x, int y);
void	draw_background(t_game *g);
void	draw_background2(t_game *g);
void	free_niveau(t_game *g);
void	images_niv_2(t_game *g);
void	images_niv_3(t_game *g);
void	find_level(t_game *g);
void	draw_background3(t_game *g);
void	call_exit(t_game *g, int x, int y);
void	find_pos_p(t_game *game, int x, int y);
void	passer_niv_suivant(t_game *g);

#endif
