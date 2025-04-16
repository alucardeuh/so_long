/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalolla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:51:37 by amalolla          #+#    #+#             */
/*   Updated: 2025/02/10 10:51:38 by amalolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*mot;

	i = 0;
	j = 0;
	mot = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!mot)
		return (NULL);
	while (s1[i] != '\0')
	{
		mot[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mot[i + j] = s2[j];
		j++;
	}
	mot[i + j] = '\0';
	return (mot);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0')
	{
		i++;
	}
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	mandatory(int fd, char **buff)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buff)
		return (0);
	return (1);
}
