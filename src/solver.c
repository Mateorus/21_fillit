/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:42:52 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/09 01:43:49 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_map(t_map *map)
{
	int			i;
	uint16_t	side;

	side = map->side;
	ft_memset(map, 0xFF, sizeof(*map));
	i = -1;
	while (++i < side)
	{
		map->row[i] >>= side;
	}
	map->side = side;
}

int		can_paste(t_map *map, t_etr *tetr)
{
	uint16_t	b;
	int			pos;
	int			side;

	pos = tetr->pos;
	side = map->side;
	b = (((map->row[pos / side] << pos % side) & 0xF000) +
		(((map->row[pos / side + 1] << pos % side) & 0xF000) >> 4) +
		(((map->row[pos / side + 2] << pos % side) & 0xF000) >> 8) +
		(((map->row[pos / side + 3] << pos % side) & 0xF000) >> 12));
	if (b & tetr->value)
		return (0);
	return (1);
}

void	paste_or_remove(t_map *map, t_etr *tetr)
{
	int	pos;
	int	side;

	pos = tetr->pos;
	side = map->side;
	map->row[pos / side] ^= (tetr->value & 0xF000) >> pos % side;
	map->row[pos / side + 1] ^= ((tetr->value & 0x0F00) << 4) >> pos % side;
	map->row[pos / side + 2] ^= ((tetr->value & 0x00F0) << 8) >> pos % side;
	map->row[pos / side + 3] ^= ((tetr->value & 0x000F) << 12) >> pos % side;

}

int		arrange(t_map *map, t_etr *tetr)
{
	int	end_of_map;

	if (!(tetr->value))
		return (1);
	end_of_map = map->side * map->side;
	while (tetr->pos < end_of_map)
	{
		if (can_paste(map, tetr))
		{
			paste_or_remove(map, tetr);
			if (arrange(map, tetr + 1))
				return (1);
			paste_or_remove(map, tetr);
		}
		tetr->pos++;
	}
	tetr->pos = 0;
	return (0);
}

void	solver(t_map *map, t_etr *set, int total)
{
	map->side = ft_sqrt(total * 4);
	get_map(map);
	while (!arrange(map, set))
	{
		map->side++;
		get_map(map);
	}
}
