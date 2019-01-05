/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:25:21 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/27 14:31:08 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: fillit <input file>\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("no such file\n");
		return (1);
	}
	fillit(fd);

/*	t_sjt	arr[4];
	int		i;

	pop_arrs(arr, 4);
	while (permute(arr, 4))
	{
		i = -1;
		while (++i < 4)
			ft_putnbr(arr[i].num);
		ft_putchar('\n');
	}
	*/
}
