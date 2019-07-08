/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:09:15 by hiantrin          #+#    #+#             */
/*   Updated: 2019/06/30 14:09:31 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **backtracking(char ***str, int num_tit)
{
    char    **map;
    int     i;
    int     c;
    
    i = num_tit;
    map = ft_map(i);
    while (cherche_count(map, str[num_tit - 1]) != 4)
    {
        map = solve(str, num_tit, map);
        if (cherche_count(map, str[num_tit - 1]) == 4)
            return (map);
        c = 0;
        while (map[c] != NULL)
		{
			printf("%s\n", map[c]);
			c++;
		}
        printf("\n");
        map = clean_map(map);
        if (num_tit > 1)
        {
            map = back_track(str, num_tit, map);   
            if (cherche_count(map, str[num_tit - 1]) == 4)
                return (map);
            map = clean_map(map);
        }
        i++;
        map = ft_map(i);
    }
        return (map);
}

char    **back_track(char  ***str, int num_tit, char **map)
{
    int     i;
    int     j;
    int     c;
    char    a;

    c = 0;
    j = 0;
    i = 0;
    a = character(str[num_tit - 1]);
    while (i < 3)
    {
        str = ft_swap(str, num_tit - 1);
        map = solve(str, num_tit, map);
        if (cherche_count(map, str[num_tit - 1]) == 4)
            break ;
        map = clean_map(map);
        if (num_tit == 2)
        {
            str = ft_swap(str, num_tit - 1);
            break ;
        }
        if (i == 2)
        {
            str = ft_swap(str, num_tit - 2);
            str = swap_all(str, num_tit, 3, &a);
            i = 0;
            j++;
            if (j == 4)
            {
                if (character(str[num_tit - 1]) != a)
                    j = 0;
                else
                    break ;
            }
        }
        else
        {
            str = ft_swap(str, num_tit - 2);
            i++;
        }
        map = solve(str, num_tit, map);
        if (cherche_count(map, str[num_tit - 1]) == 4)
            break ;
        map = clean_map(map);
    }
    return (map);
}

char    ***swap_all(char ***str, int num_tit, int c, char *a)
{
    int b;

    b = num_tit - c;
    if (character(str[b - 1]) == *a && b > 1)
    {
        while (b < num_tit)
        {
            ft_swap(str, b);
            b++;
        }
        str = swap_all(str, num_tit, c + 1, a);
        *a =  character(str[b - 1]);
    }
    else
    {
        while (b < num_tit)
        {
            ft_swap(str, b);
            b++;
        }
    }
    return (str);
}

char    ***ft_swap(char  ***str, int i)
{
    char    **tmp;

    tmp = alloc_tmp(str[i - 1]);
    str[i - 1] = str[i];
    str[i] = tmp;
    return (str);
}
