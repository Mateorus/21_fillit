/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:18:36 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/06 14:32:58 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		pop_block(char *map, char c)
{
	while (*map)
	{
		if (*map == c)
			*map = '.';
		map++;
	}
	return (0);
}

int		push_block(char *map, char *block, int map_side, char c)
{
	int i;
	int	len;

	i = 0;
	len = ft_strchr(block, '\n') - block;
	block = ft_strchr(block, c);
	while (*(block + 1))
	{
		if (map[i] == '.' && *block == c)
			map[i++] = *block++;
		else if (*block == '\n')
		{
			if (!(i < (map_side + 1) * (map_side - 1)))
				return (pop_block(map, c));
			i += map_side + 1 - len;
			block++;
		}
		else if (*block++ == '.')
			i++;
		else
			return (pop_block(map, c));
	}
	return (1);
}

int		arrange(char **map, char **set, int map_side, char c)
{
	char	*cur_map;

	if (!*set)
		return (1);
	cur_map = *map;
	while (*cur_map)
	{
		if (push_block(cur_map, *set, map_side, c))
		{
			if (arrange(map, set + 1, map_side, c + 1))
				return (1);
			pop_block(*map, c);
		}
		cur_map++;
	}
	return (0);
}

char	*get_square(char **set, int total)
{
	char	*map;
	int		map_side;

	map_side = sqr_root_ceiling(4 * total);
	map = NULL;
	get_map(&map, map_side);
	while (!arrange(&map, set, map_side, 'A'))
		get_map(&map, ++map_side);
	return (map);
}
