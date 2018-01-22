/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:49:03 by lsauvage          #+#    #+#             */
/*   Updated: 2018/01/22 15:28:15 by lsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

/*
** Backtracking
*/
int		solve_map(t_map *map, t_list *list)
{
	t_point		*point;
	t_etris		*tetri;

	if (list == NULL)
		return (1);
	point->y = 0;
	tetri = (t_etris *)(list->content);
	while (point->y < map->size - tetri->height + 1)
	{
		point->x = 0;
		while (point->x < map->size - tetri->width + 1)
		{
			if (place(tetri, map, point->x, point->y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetri, map, point_new(point->x, point->y), '.');
			}
			point->x++;
		}
		point->y++;
	}
	return (0);
}

/*
** Arrondi sup de la racine de n
*/

int		high_sqrt(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

/*
** Resolution en partant de la plus petite taille possible
*/

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = high_sqrt(ft_lstcount(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
