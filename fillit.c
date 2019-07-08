/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:35:05 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/08 18:58:03 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage(void)
{
	write(1, "usage: ./fillit target_file\n", 28);
}

void	ft_main(char *argv, int num_tit)
{
	char	***str;
	char	**map;
	int		i;

	str = save(argv, num_tit);
	map = backtracking(str, num_tit);
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		num_tit;

	if (argc != 2)
		usage();
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (verification(argv[1]) == 1)
		{
			if ((num_tit = count_tetris(argv[1])) > 0)
				ft_main(argv[1], num_tit);
			else
				write(1, "error\n", 6);
		}
		else
			write(1, "error\n", 6);
	}
	return (0);
}
