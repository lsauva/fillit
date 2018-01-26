/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsauvage <lsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:59:32 by lsauvage          #+#    #+#             */
/*   Updated: 2018/01/25 16:43:51 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"

int			main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr("utilisation : fillit input_file\n ");
		return (1);
	}
	if ((list = read_tetri(open(av[1], O_RDONLY), NULL, 'A')) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solve(list);
	print_map(map);
	free_map(map);
	free_list(list);
	return (0);
}
