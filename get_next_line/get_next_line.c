/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:50:17 by amalolla          #+#    #+#             */
/*   Updated: 2025/02/10 10:50:18 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*str;

	if (mandatory(fd, &buff) == 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	if (!read_and_update_buffer(fd, &str, &buff))
		return (NULL);
	if (ft_strchr(str, '\n') != NULL)
		free(buff);
	line = extract_line(str);
	str = update_static_str(str);
	return (line);
}

int	read_and_update_buffer(int fd, char **str, char **buff)
{
	int		byte_read;
	char	*temp;

	while (ft_strchr(*str, '\n') == NULL)
	{
		byte_read = read(fd, *buff, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			free(*buff);
			if (byte_read == 0)
				break ;
			return (0);
		}
		(*buff)[byte_read] = '\0';
		temp = ft_strjoin(*str, *buff);
		free(*str);
		*str = temp;
	}
	return (1);
}

char	*update_static_str(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc((ft_strlen(str) - i) * sizeof(char));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*extract_line(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str || !*str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new_str = malloc((i + (str[i] == '\n') + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	if (str[i] == '\n')
	{
		new_str[j] = '\n';
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

/*int main(void)
{
	int		fd;
	char	*line;

	fd = open("map.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
