/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstiedem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:30:52 by gstiedem          #+#    #+#             */
/*   Updated: 2019/01/05 15:28:15 by gstiedem         ###   ########.fr       */
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
void	fillit(int fd);
void	assert(int i);
int		validator(int fd, char **set);
void	prepare_tetraminos(char **set);
void	trim(char *tetr);
char	*get_square(char **set, int total);
void	print_square(char *square);
void	get_map(char **map, int map_side);
int		sqr_root_ceiling(int x);
void	clean_map(char *map);
#endif
