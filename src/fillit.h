/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:30:52 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/09 13:46:13 by gstiedem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define CARD_SIZE		20
# define MAX_CARDS		26

typedef struct	s_etr
{
	int				pos;
	uint16_t		value;
}				t_etr;
typedef struct	s_map
{
	int			side;
	uint16_t	row[16];
}				t_map;
int		validator(int fd, t_etr *set);
void	solver(t_map *map, t_etr *set, int total);
void	print_map(t_map *map, t_etr *tetr);
int		ft_sqrt(int x);
#endif
