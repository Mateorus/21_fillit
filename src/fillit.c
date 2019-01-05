/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:17:24 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/24 20:21:33 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(int fd)
{
	char	**argv;
	char	*square;
	int		total;

	if (!(argv = malloc(sizeof(*argv) * (MAX_CARDS + 1))))
	{
		ft_putstr("malloc failed\n");
		exit(0);
	}
	total = validator(fd, argv);
	argv[total] = 0;
	prepare_tetraminos(argv);
	square = get_square(argv, total);
	print_square(square);
}
