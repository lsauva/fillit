/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:42:09 by lsauvage          #+#    #+#             */
/*   Updated: 2017/12/01 17:20:36 by lsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/libft.h"

void		free_map(t_map *map);
void		print_map(t_map *map);
t_map		*map_new(size_t size);
int			place(t_etris *tetris, t_map *map, t_point *point);
void		set_piece(t_etris *tetris, t_map *map, t_point *point, char c);
#endif
