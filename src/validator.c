/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:19:11 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/07 00:08:13 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	assert(int i)
{
	if (!i)
	{
		ft_putstr("error\n");
		exit(0);
	}
}

int		valid_block(char *buf)
{
	int	neighbors;
	int	i;

	neighbors = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				neighbors++;
			if (i > 0 && buf[i - 1] == '#')
				neighbors++;
			if (i > 4 && buf[i - 5] == '#')
				neighbors++;
			if (i < 14 && buf[i + 5] == '#')
				neighbors++;
		}
	}
	if (neighbors != 6 && neighbors != 8)
		return (0);
	return (1);
}

void	valid_card(char *buf)
{
	int	counter;
	int	i;

	counter = 0;
	i = -1;
	while (++i < CARD_SIZE)
	{
		if ((i + 1) % 5 && (buf[i] != '.' && buf[i] != '#'))
			assert(0);
		if (!((i + 1) % 5) && buf[i] != '\n')
			assert(0);
		if (buf[i] == '#')
			counter++;
	}
	assert(counter == 4 && valid_block(buf));
}

void	validator(int fd)
{
	int		rd;
	int		last_rd;
	int		total;
	char	buf[CARD_SIZE + 1];

	total = 0;
	while ((rd = read(fd, buf, CARD_SIZE + 1)) >= 20)
	{
		assert(buf[rd - 1] == '\n');
		buf[CARD_SIZE] = 0;
		valid_card(buf);
		last_rd = rd;
		total++;
	}
	if (rd != 0 || !total || total > MAX_CARDS || last_rd != CARD_SIZE)
		assert(0);
}
