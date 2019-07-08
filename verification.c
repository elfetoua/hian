/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:54:49 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/08 19:43:18 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		dashes_per_bloc(char *file)
{
	int		fd;
	int		i;
	int		dash_cnt;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 1;
	dash_cnt = 0;
	while (get_next_line(fd, &line))
	{
		while (*line)
		{
			if (*line == '#')
				dash_cnt++;
			line++;
		}
		i++;
		if (i / 5 == 1)
		{
			if (dash_cnt != 4)
				return (0);
			dash_cnt = 0;
			i = 0;
		}
	}
	close(fd);
	if (cnx_per_bloc(file) == 0)
		return (0);
	return (1);
}

int		verification(char *file)
{
	int		fd;
	int		i;
	char	*line;
	int		j;

	i = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		if ((ft_strlen(line) != 4 && i % 5 != 0) || (ft_strlen(line) != 0
					&& i % 5 == 0))
			return (0);
		j = 0;
		if (i % 5 != 0)
		{
			while (line[j])
			{
				if (!ft_strchr(".#", line[j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	if ((i % 5) != 0)
		return (0);
	close(fd);
	if (!dashes_per_bloc(file))
		return (0);
	return (1);
}

int		check(char **str)
{
	int	i;
	int	j;
	int	dash_cnx;

	dash_cnx = 0;
	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		if (str[i][j] == '#')
		{
			if (i == 3)
			{
				if (str[i][j + 1] == '#')
					dash_cnx++;
			}
			else
			{
				if (str[i][j + 1] == '#')
					dash_cnx++;
				if (str[i + 1][j] == '#')
					dash_cnx++;
			}
		}
		j++;
		if (j == 4)
		{
			i++;
			j = 0;
		}
	}
	if (dash_cnx == 3 || dash_cnx == 4)
		return (1);
	return (0);
}

int		cnx_per_bloc(char *file)
{
	int		fd;
	char	*line;
	char	**str;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * 5);
	str[4] = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		str[i] = ft_strnew(4);
		ft_strcpy(str[i], line);
		if (++i == 4)
		{
			if (check(str) == 0)
				return (0);
			if (get_next_line(fd, &line) != 1)
				return (1);
			i = 0;
		}
	}
	close(fd);
	freedoubledem(str);
	return (1);
}
