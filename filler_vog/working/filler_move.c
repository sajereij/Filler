/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:15:38 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/13 13:21:36 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		score_heat(t_d *d, int hmap_row, int hmap_col)
{
	int	pc_col;
	int	pc_row;
	int score;

	score = 0;
	pc_row = -1;
	while (++pc_row < d->py && pc_row + hmap_row < d->my)
	{
		pc_col = -1;
		while (++pc_col < d->px && pc_col + hmap_col < d->mx)
			if (d->pc[pc_row][pc_col] == '*')
				score += d->hmap[hmap_row + pc_row][hmap_col + pc_col];
	}
	return (score);
}

int		fit_pc(t_d *d, int token_row, int token_col, int *valid_move)
{
	int		pc_row;
	int		pc_col;
	int		token;
	int		overlap;

	pc_row = -1;
	token = (d->pnb == 1) ? 'O' : 'X';
	overlap = 0;
	while (++pc_row < d->py && (token_row + pc_row < d->my))
	{
		pc_col = -1;
		while (++pc_col < d->px && (token_col + pc_col < d->mx))
			if (d->pc[pc_row][pc_col] == '*')
			{
				if (d->hmap[token_row + pc_row][token_col + pc_col] == 0)
					return (-1);
				if (d->map[token_row + pc_row][token_col + pc_col] == token \
				|| d->map[token_row + pc_row][token_col + pc_col] == token + 32)
					overlap++;
				if (overlap > 1)
					return (-1);
			}
	}
	return ((overlap != 1) ? -1 : (*valid_move = 1));
}

int		adjust_onto_map(int tmp)
{
	return ((tmp < 0) ? 0 : tmp);
}

void	try_pc(t_d *d, int cur_row, int cur_col, int *valid_move)
{
	int	pc_row;
	int	pc_col;
	int tmp;

	cur_row = adjust_onto_map(cur_row);
	cur_col = adjust_onto_map(cur_col);
	pc_row = -1;
	while (((++pc_row + cur_row) < d->my - d->py + 1) && (pc_row < d->py))
	{
		pc_col = -1;
		while ((++pc_col + cur_col < d->mx - d->px + 1) && pc_col < d->px)
		{
			if (fit_pc(d, pc_row + cur_row, pc_col + cur_col, valid_move) == 1)
				if ((tmp = score_heat(d, pc_row + cur_row, pc_col + cur_col)) \
					< d->heat_score)
				{
					d->heat_score = tmp;
					(d->pnb == 1) ? (d->lmox = ((pc_col + cur_col) - d->plx)) \
						: (d->lmxx = ((pc_col + cur_col) - d->plx));
					(d->pnb == 1) ? (d->lmoy = ((pc_row + cur_row) - d->pty)) \
						: (d->lmxy = ((pc_row + cur_row) - d->pty));
				}
		}
	}
}
