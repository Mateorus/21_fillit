/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:34:44 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/23 11:27:10 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_col(char *tetr)
{
	int 	i;
	char	*tmp;

	tmp = tetr;
	i = 0;
	while (tetr[i])
	{
		if (tetr[i + 1] == '\n')
			i++;
		*tmp = tetr[i++];
		tmp++;
	}
	*tmp = 0;
}

void	trim(char *tetr)
{
	int i;
	int j;

	i = 5;
	while (tetr[i - 2] == '.' && tetr[i * 2 - 2 ] == '.' &&
			tetr[i * 3 - 2] == '.' && tetr[i * 4 - 2] == '.')
	{
		delete_col(tetr);
		i--;
	}
	j = 3;
	while (!(ft_strchr(&tetr[i * j], '#')))
	{
		tetr[i * j] = 0;
		j--;
	}
}
