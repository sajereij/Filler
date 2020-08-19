/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:43:22 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/19 15:43:22 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <unistd.h>
// # include <stdlib.h>
// # include <fcntl.h>

typedef struct	s_data
{
	int		fd;
	int		pnb;
	char	**map;
	char	**pc;
	int		mx;
	int		my;
	int		px;
	int		py;
}				t_d;

typedef struct	s_piece
{
	int		x;
	int		y;
}				t_p;

#endif
