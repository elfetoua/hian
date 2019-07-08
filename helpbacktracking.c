/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpbacktracking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:30:06 by hiantrin          #+#    #+#             */
/*   Updated: 2019/07/02 21:30:23 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int cherche_count(char **map, char **str)
{
    int count;
    int i;
    int j;
    char    c;

    i = 0;
    j = 0;
    count = 0;
    c = character(str);
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

char    character(char **str)
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
                return (str[i][j]);
            }
            j++;
        }
        i++;
    }
    return ('.');
}

char    **alloc_tmp(char **str)
{
    char    **tmp;
    int     i;  

    i = 0;
    tmp = malloc(sizeof(char *) * 5);
    tmp[4] = NULL;
    while (tmp[i] != NULL)
    {
        tmp[i] = (char *)malloc(sizeof(char) * 5);
        tmp[i][4] = '\0';
        i++;
    }
    i = 0;
    while (str[i] != NULL)
    {
        tmp[i] = str[i];
        i++;
    }
    return (str);
}

char    **clean_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            map[i][j] = '.';
            j++;
        }
        i++;
    } 
    return (map);
}

char    **ft_map(int   num)
{
    char    **str;
    int     i;
    int     j;

    i = 1;
    while ((num * 4) > (i * i))
        i++;
    str = (char **)malloc(sizeof(char *) * (i + 1));
    str[i] = NULL;
    num = i;
    i = 0;
    while (i < num)
    {
        j = 0;
        str[i] = malloc(sizeof(char) * (num + 1));
        str[i][j] = '\0';
        while (j < num)
        {
            str[i][j] = '.';
            j++;
        }
        i++;
    }
    return (str);
}