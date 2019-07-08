/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:35:41 by elfetoua          #+#    #+#             */
/*   Updated: 2019/07/08 19:06:24 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"

#include <stdio.h>

int		verification(char *file);
int		cnx_per_bloc(char *file);
void	usage(void);
int		check(char **str);
int		dashes_per_bloc(char *file);
int     count_tetris(char *file);
char    **tetris(int fd);
char    ***save(char *file, int num_tit);
char    ***alpha_tetris(char ***str, int num_tit);
char    **solve(char ***str, int num_tit, char **map);
char    **ft_map(int   num);
char    **remplir(char ***str, char **map, int num_tit);
char    **rem_map(char **str, char **map);
char    **test1(char **map, char **str, int s_i, int s_j);
int     fonc(char **str, int *i, int *j);
char	**clean(char **map, char a);
int     cherche(char **map, int *a, int *b);
char    **backtracking(char ***str, int num_tit);
int		cherche_count(char **map, char	**str);
char    **back_track(char  ***str, int num_tit, char **map);
char    **alloc_tmp(char **str);
char    character(char **str);
char    ***ft_swap(char  ***str, int i);
char    ***swap_all(char ***str, int num_tit, int c, char *a);
char    **clean_map(char **map);
void	freedoubledem(char **map);

# endif
