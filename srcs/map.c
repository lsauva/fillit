/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:25:13 by lsauvage          #+#    #+#             */
/*   Updated: 2018/01/18 16:46:28 by lsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

/*
** map_new alloue l'espace memoire pour une nouvelle structure map avec
** la taille specifiee
*/

t_map	*map_new(size_t taille)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = taille;
	map->array = (char **)ft_memalloc(sizeof(char *) * taille);
	i = 0;
	while (i < taille)
	{
		map->array[i] = ft_strnew(taille);
		j = 0;
		while (i < taille)
		{
			map->array[i][j] = '.';
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

/*
** Print map affiche sur la sortie std une map allouee.
*/

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** Place un tetrimino a une position specifique sur la map, et verifie si la
** place est dispo
*/

int		place(t_etris *tetri, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			
		}
	}
}
