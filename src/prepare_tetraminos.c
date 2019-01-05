/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_tetraminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:21:53 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/23 16:51:46 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*to_up(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
	{
		if (*s == '#')
		{
			*(s - 5) = '#';
			*s = '.';
		}
		s++;
	}
	return (tmp);
}

char	*to_left(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
	{
		if (*s == '#')
		{
			*(s - 1) = '#';
			*s = '.';
		}
		s++;
	}
	return (tmp);
}

void	shift_to_left_corner(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '.' && i < 4)
		i++;
	if (i == 4)
		shift_to_left_corner(to_up(s));
	i = 0;
	while (s[i] == '.' && i < 20)
		i += 5;
	if (i == 20)
		shift_to_left_corner(to_left(s));
}

void	sharp_to_alpha(char *s, int num)
{
	char	c;

	c = 'A';
	while (*s)
	{
		if (*s == '#')
			*s = c + num;
		s++;
	}
}

void	prepare_tetraminos(char **set)
{
	int	i;

	i = 0;
	while (*set)
	{
		shift_to_left_corner(*set);
		trim(*set);
		sharp_to_alpha(*set, i);
		set++;
		i++;
	}

}
