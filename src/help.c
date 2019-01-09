/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 01:35:55 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/09 14:19:08 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int x)
{
	int	i;
	int	sum;

	if (x == 0 || x == 1)
		return (x);
	i = 0;
	sum = 0;
	while (sum < x)
	{
		i++;
		sum = i * i;
	}
	return (i);
}

static void	write_value(char *map, uint16_t value, char c, int side)
{
	value >> 15 & 1 ? map[0] = c : 0;
	value >> 14 & 1 ? map[1] = c : 0;
	value >> 13 & 1 ? map[2] = c : 0;
	value >> 12 & 1 ? map[3] = c : 0;
	value >> 11 & 1 ? map[0 + side] = c : 0;
	value >> 10 & 1 ? map[1 + side] = c : 0;
	value >> 9 & 1 ? map[2 + side] = c : 0;
	value >> 8 & 1 ? map[3 + side] = c : 0;
	value >> 7 & 1 ? map[0 + side * 2] = c : 0;
	value >> 6 & 1 ? map[1 + side * 2] = c : 0;
	value >> 5 & 1 ? map[2 + side * 2] = c : 0;
	value >> 4 & 1 ? map[3 + side * 2] = c : 0;
	value >> 3 & 1 ? map[0 + side * 3] = c : 0;
	value >> 2 & 1 ? map[1 + side * 3] = c : 0;
	value >> 1 & 1 ? map[2 + side * 3] = c : 0;
	value  & 1 ? map[3 + side * 3] = c : 0;
}

void		print_map(t_map *map, t_etr *tetr)
{
	char	*sm;
	int		size;
	int		i;
	char	c;

	size = map->side * map->side;
	if (!(sm = malloc(sizeof(*sm) * (size + 1))))
	{
		ft_putendl("malloc failed");
		exit(0);
	}
	sm[size] = 0;
	ft_memset(sm, '.', size);
	c = 'A';
	i = -1;
	while (tetr[++i].value)
		write_value(sm + tetr[i].pos, tetr[i].value, c++, map->side);
	i = -1;
	while (sm[++i])
	{
		ft_putchar(sm[i]);
		(i + 1) % map->side ? 0 : ft_putchar('\n');
	}
}
