/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:13:59 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/08 19:00:53 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tetris(char *file)
{
	int		i;
	int		fd;
	int		count;
	char	*line;

	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		if (i == 4)
		{
			count++;
			i = -1;
		}
	}
	close(fd);
	if (count > 26)
		return (0);
	return (count);
}

char	**tetris(int fd)
{
	char	*line;
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * 5);
	str[4] = NULL;
	while (i < 4)
	{
		get_next_line(fd, &line);
		str[i] = ft_strnew(5);
        ft_strcpy(str[i], line);
		i++;
	}
	get_next_line(fd, &line);
	return (str);
}

char	***save(char *file, int num_tit)
{
	char	***str;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	str = (char ***)malloc(sizeof(char **) * num_tit);
	while (i < num_tit)
	{
		str[i] = tetris(fd);
		i++;
	}
	close(fd);
	return (alpha_tetris(str, num_tit));
}

char	***alpha_tetris(char ***str, int num_tit)
{
	int i;
	int j;
	int a;

	a = 0;
	while (a < num_tit)
	{
		i = 0;
		while (str[a][i] != NULL)
		{
			j = 0;
			while (str[a][i][j] != '\0')
			{
				if (str[a][i][j] == '#')
					str[a][i][j] = a + 'A';
				j++;
			}
			i++;
		}
		a++;
	}
	return (str);
}
