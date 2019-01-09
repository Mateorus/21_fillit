/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:25:21 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/09 14:22:32 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_etr		set[MAX_CARDS + 1];
	t_map		map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit <input file>\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("can't open ");
		ft_putendl(argv[1]);
		return (1);
	}
	ft_bzero(set, sizeof(set));
	solver(&map, set, validator(fd, set));
	print_map(&map, set);
}
