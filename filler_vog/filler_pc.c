/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:48:59 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/14 14:50:10 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**trim_pc(t_d *d, int mx_row, int mx_col)
{
	int		i;
	char	**tmp;
	i = -1;

	if (!(tmp = ft_memalloc((mx_row - d->pty + 2) * sizeof(char *))))
		return (NULL);
	while ((++i + d->pty) <= mx_row)
		tmp[i] = ft_strsub(d->pc[d->pty + i], d->plx, mx_col - d->plx + 1);
	tmp[i] = NULL;
	ft_strarr_free(d->pc);
	d->py -= (d->pty) + (d->py - mx_row - 1);
	d->px = ft_strlen(tmp[0]);
	return (tmp);
}

void	find_bottom_right_trim(t_d *d)
{
	int pc_endy;
	int	pc_endx;
	int	cur_col;
	int	cur_row;

	pc_endy = d->pty;
	pc_endx = d->plx;
	cur_row = -1;
	while (++cur_row < d->py)
	{
		cur_col = -1;
		while (++cur_col < d->px)
			if (d->pc[cur_row][cur_col] == '*')
			{
				pc_endy = (cur_row > pc_endy) ? cur_row : pc_endy;
				pc_endx = (cur_col > pc_endx) ? cur_col : pc_endx;
			}
	}
	d->pc = trim_pc(d, pc_endy, pc_endx);
}

int		find_top_left(t_d *d)
{
	int	cur_col;
	int	cur_row;
	int	valid_pc;

	valid_pc = 0;
	cur_row = -1;
	d->plx = d->px;
	d->pty = d->py;
	while (++cur_row < d->py)
	{
		cur_col = -1;
		while (++cur_col < d->px)
			if (d->pc[cur_row][cur_col] == '*')
			{
				d->pty = (cur_row < d->pty) ? cur_row : d->pty;
				d->plx = (cur_col < d->plx) ? cur_col : d->plx;
				valid_pc = 1;
			}
	}
	return (valid_pc);
}

int		adjust_pc(t_d *d)
{
	if (find_top_left(d))
	{
		find_bottom_right_trim(d);
		return (1);
	}
	else
		return (-1);
}
