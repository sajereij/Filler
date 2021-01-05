/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:16:14 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/12 20:05:28 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_heatmap(t_d *d, int oppo_y, int oppo_x)
{
	int	cur_col;
	int	cur_row;
	int distance;

	cur_row = -1;
	while (++cur_row < d->my)
	{
		cur_col = -1;
		while (++cur_col < d->mx)
		{
			distance = ft_abs(cur_col - oppo_x) > ft_abs(cur_row - oppo_y) ? \
				ft_abs(cur_col - oppo_x) : ft_abs(cur_row - oppo_y);
			if ((d->hmap[cur_row][cur_col]) > distance)
				d->hmap[cur_row][cur_col] = distance;
		}
	}
}

void	map_to_heatmap(t_d *d)
{
	int	row;
	int	col;

	row = -1;
	d->e = (d->pnb == 1) ? 'X' : 'O';
	while (++row < d->my)
	{
		col = -1;
		while (++col < d->mx)
			if (d->map[row][col] == d->e || d->map[row][col] == d->e + 32)
				fill_heatmap(d, row, col);
	}
}

void	max_out_hmap(t_d *d)
{
	int	x;
	int	y;
	int	tmp;

	tmp = d->mx > d->my ? d->mx : d->my;
	y = -1;
	while (++y < d->my)
	{
		x = -1;
		while (++x < d->mx)
			d->hmap[y][x] = tmp;
	}
}

void	make_heatmap(t_d *d)
{
	d->hmap = ft_tabarr_malloc(d->my, d->mx);
	max_out_hmap(d);
	map_to_heatmap(d);
}

int		choose_move(t_d *d)
{
	make_heatmap(d);
	return (play_pc(d));
}
