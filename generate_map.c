/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <amalolla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 18:10:10 by amalolla          #+#    #+#             */
/*   Updated: 2025-04-20 18:10:10 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"

char	**copy_map(t_game *game)
{
	char	**new_char;
	int		count;
	int		i;
	int		j;

	count = game->hm * game->lm;
	new_char = malloc(sizeof(char *) * (count));
	i = 0;
	while (i < game->hm)
	{
		new_char[i] = malloc(sizeof(char) * game->lm);
		j = 0;
		while (j < game->lm)
		{
			new_char[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	return (new_char);
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
	game->lm = ft_strlen(ligne) - 1;
	while (ligne)
	{
		map[i] = ligne;
		i++;
		count_collectible(ligne, game);
		ligne = get_next_line(fd);
	}
	map[i] = NULL;
	game->hm = i;
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
