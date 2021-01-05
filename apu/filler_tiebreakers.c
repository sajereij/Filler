/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_tiebreakers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:27:16 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/27 19:54:13 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_center(t_d *d, int offer_row, int offer_col)
{
	int		mid_row;
	int		mid_col;

	mid_row = d->my / 2;
	mid_col = d->my / 2;
	if ((ft_abs(mid_row - offer_row) + ft_abs(mid_col - offer_col) \
	< ft_abs(mid_row - d->lmoy) + ft_abs(mid_col - d->lmox)) && d->pnb == 1)
		return (1);
	if ((ft_abs(mid_row - offer_row) + ft_abs(mid_col - offer_col)) \
	< (ft_abs(mid_row - d->lmxy) + ft_abs(mid_col - d->lmxx)) && d->pnb == 2)
		return (1);
	return (0);
}

int		tiebreaker(t_d *d, int proposed_row, int proposed_col)
{
	int		ret;

	ret = check_center(d, proposed_row, proposed_col);
	return (ret);
}
