/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:01:17 by hiantrin          #+#    #+#             */
/*   Updated: 2019/06/28 20:01:18 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **rem_map(char **str, char **map)
{
    int i;
    int j;

    i = 0;
    while (str[i] != NULL)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            if (str[i][j] >= 'A' && str[i][j] <= 'Z' )
            {
                map = test1(map, str, i, j);
                return (map);
            }
            j++;
        }
        i++;
    }
    return (map);
}

char    **remplir(char ***str, char **map, int num_tit)
{
    int i;

    i = 0;
    while (i < num_tit)
    {
        map = rem_map(str[i], map);
        if (cherche_count(map, str[i]) != 4)
            break ;
        i++;
    }
    return (map);
}

char    **solve(char ***str, int num_tit, char **map)
{
    map = remplir(str, map, num_tit);
    return(map);
}
