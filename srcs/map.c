/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:25:13 by lsauvage          #+#    #+#             */
/*   Updated: 2017/12/20 18:46:17 by lsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** map_new alloue l'espace memoire pour une nouvelle structure map avec
** la taille specifiee
*/

t_map	*map_new(int taille)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_mamalloc(sizeof(t_map));
	map->size = taille;
	map->array = (char **)ft_mamalloc(sizeof(char *) * taille);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(taille);
		j = 0;
		while (i < size)
		{
			map->arrat[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*
** free_map libere l'espace memoire alloue pour une structure map
*/

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
