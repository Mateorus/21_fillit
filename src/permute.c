/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 11:46:00 by gstiedem          #+#    #+#             */
/*   Updated: 2018/12/27 15:25:32 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * 						Steinhaus–Johnson–Trotter algorithm 
 *
*/
#include "fillit.h"

t_sjt	*swap(t_sjt *largest)
{
	t_sjt	tmp;

	if (largest->direction == LEFT)
	{
		tmp = *largest;
		*largest = *(largest - 1);
		*(largest - 1) = tmp;
		return (largest - 1);
	}
	else
	{
		tmp = *largest;
		*largest = *(largest + 1);
		*(largest + 1) = tmp;
		return (largest + 1);
	}
}

t_sjt	*find_largest_mobile(t_sjt arr[], int total)
{
	int		i;
	int		num;
	t_sjt	*largest;

	largest = NULL;
	num = -1;
	i = -1;
	while (++i < total)
	{
		if (arr[i].direction == LEFT && i != 0 &&
			arr[i - 1].num < arr[i].num && arr[i].num > num)
				largest = &arr[i];
		
		if (arr[i].direction == RIGHT && i != total - 1 &&
			arr[i + 1].num < arr[i].num && arr[i].num > num)
				largest = &arr[i];
		largest != NULL ? (num = largest->num) : (num = 0);
	}
	return (largest);
}

void	change_direction(t_sjt arr[], t_sjt current, int total)
{
	int	i;

	i = -1;
	while (++i < total)
	{
		if (arr[i].num > current.num)
			arr[i].direction = ~arr[i].direction;
	}
}

int		permute(t_sjt arr[], int total)
{
	t_sjt	*largest;

	if (total == 1 && arr[0].direction == LEFT)
	{
		arr[0].direction = ~arr[0].direction;
		return (1);
	}
	if ((largest = find_largest_mobile(arr, total)))
	{
		largest = swap(largest);
		change_direction(arr, *largest, total);
		return (1);
	}
	return (0);
}
