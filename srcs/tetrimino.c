/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:23:49 by lsauvage          #+#    #+#             */
/*   Updated: 2018/01/22 15:29:08 by lsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

/*
** Creation d'une structure point. abscisse x, ordonnee y.
*/

t_point		*point_new(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

/*
** Creation d'une structure tetrimino.
*/

t_etris		*tetris_new(char **pos, int width, int height, char value)
{
	t_etris	*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

/*
** Libere l'espace memoire d'un tetrimino.
*/

void		free_tetris(t_etris *tetris)
{
	int	y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)(&(tetris->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetris->pos)));
	ft_memdel((void **)&tetris);
}

/*
** Libere l'espace memoire d'une liste cree avec read_tetri
*/

t_list		*free_list(t_list *list)
{
	t_etris	*tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_etris *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
