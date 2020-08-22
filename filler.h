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
# include <stdio.h>

typedef struct	s_data
{
	int		fd;
	int		pnb;
	int		e; //enemy
	int		prev_turn;
	char	**map;
	char	**pc;
	int		**hmap;
	int		my;
	int		mx;
	int		px;
	int		py;
	int		lmxx;
	int		lmxy;
	int		lmox;
	int		lmoy;
	int		moves;
	int		cx;
	int		cy;
}				t_d;

void	init_struct(t_d *d);
void	set_player(t_d *d);
void	get_data(t_d *d);
void	play_pc(t_d *d);
void	choose_move(t_d *d);

#endif
