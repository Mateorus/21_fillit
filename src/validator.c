/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:19:11 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/09 14:35:08 by gstiedem         ###   ########.fr       */
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

void	write_card(char *buf, t_etr *tetr)
{
	int	i;

	i = 0;
	while (*buf)
	{
		if (*buf == '#')
			tetr->value += 0x8000 >> i;
		if (*buf != '\n')
			i++;
		buf++;
	}
	while (!(tetr->value & 0xF000))
		tetr->value <<= 4;
	while (!(tetr->value & 0x8888))
		tetr->value <<= 1;
}

int		validator(int fd, t_etr *set)
{
	int		rd;
	int		last_rd;
	int		total;
	char	buf[CARD_SIZE + 1];

	total = 0;
	while ((rd = read(fd, buf, CARD_SIZE + 1)) >= 20)
	{
		total > MAX_CARDS ? assert(0) : 0;
		assert(buf[rd - 1] == '\n');
		buf[CARD_SIZE] = 0;
		valid_card(buf);
		write_card(buf, set);
		last_rd = rd;
		total++;
		set++;
	}
	if (rd != 0 || !total || last_rd != CARD_SIZE)
		assert(0);
	return (total);
}
