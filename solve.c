/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:16:14 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/19 17:16:14 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	max_out_hmap(t_d *d)
{
	int	x;
	int	y;
	int	tmp;

	tmp = d->mx > d->my ? d->mx : d->my;
	y = 0;
	while (y > -1 && y < d->my)
	{
		x = 0;
		while ((x > -1) && (x < d->mx))
		{
			d->hmap[y][x] = tmp;
			x++;
		}
		y++;
	}
}

void	fill_heatmap(t_d *d, int enemy_y, int enemy_x)
{
	int	cur_col;
	int	cur_row;
	int distance;
	
	cur_row = 0;
	while (cur_row < d->my)
	{
		cur_col = 0;
		while (cur_col < d->mx)
		{
			// distance = ft_abs(cur_row - enemy_y) + ft_abs(cur_col - enemy_x); //manhattan distance: must walk arount the block
			distance = ft_abs(cur_col - enemy_x) > ft_abs(cur_row - enemy_y) ? \
				ft_abs(cur_col - enemy_x) : ft_abs(cur_row - enemy_y);
			if ((d->hmap[cur_row][cur_col]) > distance)
				d->hmap[cur_row][cur_col] = distance;
			cur_col++;
		}
		cur_row++;
	}
}

void		enemy_presence_max(t_d *d, int y, int x)
{
	int	p;
	int	e;

	p = 0;
	e = (d->pnb == 1) ? 'X' : 'O';
	(d->map[y][x] == e) ? d->hmap[y][x] = -1 : 0;
	p = (x > 0 && d->hmap[y][x - 1] < e) ? 1 : 0;
	p += (x < d->mx && d->hmap[y][x + 1] == e) ? 1 : 0;
	p += (y > 0 && x > 0 && d->hmap[y - 1][x - 1] == e) ? 1 : 0;
	p += (y < (d->my - 1) && x < d->mx && d->hmap[y + 1][x + 1] == e) ? 1 : 0;
	p += (y < (d->my - 1) && x > 0 && d->hmap[y + 1][x - 1] == e) ? 1 : 0;
	p += (y > 0 && x < d->mx && d->hmap[y - 1][x + 1] == e) ? 1 : 0;
	p += (y < (d->my - 1) && d->hmap[y + 1][x] == e) ? 1 : 0;
	p += (y > 0 && d->hmap[y - 1][x] == e) ? 1 : 0;
}

// void		enemy_presence_maxim(t_d *d, int y, int x)
// {
// 	int	p;
// 	int	e;

// 	p = 0;
// 	e = (d->pnb == 1) ? 'X' : 'O';
// 	if (d->map[y][x] == e)
// 		d->map[y][x] = -1;
// 	p = (x > 0 && d->map[y][x - 1] < e) ? 1 : 0;
// 	p += (x < d->mx && d->map[y][x + 1] == e) ? 1 : 0;
// 	p += (y > 0 && x > 0 && d->map[y - 1][x - 1] == e) ? 1 : 0;
// 	p += (y < (d->my - 1) && x < d->mx && d->map[y + 1][x + 1] == e) ? 1 : 0;
// 	p += (y < (d->my - 1) && x > 0 && d->map[y + 1][x - 1] == e) ? 1 : 0;
// 	p += (y > 0 && x < d->mx && d->map[y - 1][x + 1] == e) ? 1 : 0;
// 	p += (y < (d->my - 1) && d->map[y + 1][x] == e) ? 1 : 0;
// 	p += (y > 0 && d->map[y - 1][x] == e) ? 1 : 0;
// }


void	fill_distance(t_d *d, int enemy_y, int enemy_x)
{
	int	cur_col;
	int	cur_row;
//	int distance;
	
	cur_row = 0;
	while (cur_row < d->my)
	{
		cur_col = 0;
		while (cur_col < d->mx)
		{
			enemy_presence_max(d, enemy_y, enemy_x);
			cur_col++;
		}
		cur_row++;
	}
}

int		count_zeros(t_d *d)
{
	int	x;
	int	y;
	int	tmp;

	tmp = 0;
	y = 0;
	while (y > -1 && y < d->my)
	{
		x = 0;
		while ((x > -1) && (x < d->mx))
		{
			if ((d->hmap[y][x] == 0))
				tmp += 1;
			x++;
		}
		y++;
	}
	return (tmp);
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
			if(d->map[row][col] == d->e || d->map[row][col] == d->e + 32)
			{
				fill_heatmap(d, row, col);
				// while (count_zeros(d) > 0)
				// 	fill_distance(d, row, col);
			}
	}
//	ft_intarr_print(d->hmap, d->my, d->mx);
	// ft_intarr_print_fd(d->hmap, d->my, d->mx, d->fd);
}

void	fill_zeros(t_d *d)
{
	int	x;
	int	y;
	int	tmp;
	int z;

	tmp = -5;
	z = count_zeros(d);
	while (z > 0)
	{
		y = 0;
		while (y > -1 && y < d->my)
		{
			x = 0;
			while (x > -1 && x < d->mx)
			{
				if (d->hmap[y][x] == 0)
				{
					// tmp = (x < d->mx - 1 && (d->hmap[y][x + 1] > 0)) ? d->hmap[y][x + 1] : 0;
					// tmp = (x > 0 && d->hmap[y][x - 1] > 0) ? d->hmap[y][x - 1] : 0;
					tmp = (y > 0 && x > 0 && d->map[y - 1][x - 1] > 0) ? d->map[y - 1][x - 1] : 0;
					// tmp = (y < (d->my - 1) && x < d->mx && d->map[y + 1][x + 1] > 0) ? d->map[y + 1][x + 1] : 0;
					// tmp = (y < (d->my - 1) && x > 0 && d->map[y + 1][x - 1] > 0) ? d->map[y + 1][x - 1] : 0;
					tmp = (y > 0 && x < d->mx && d->map[y - 1][x + 1] > 0) ? d->map[y - 1][x + 1] : 0;
					// tmp = (y < (d->my - 1) && d->map[y + 1][x] > 0) ? d->map[y + 1][x] > 0 : 0;
					tmp = (y > 0 && d->map[y - 1][x] > 0) > 0 ? d->map[y - 1][x] : 0;
					// if (y < d->my - 1 && x < d->mx && d->hmap[y + 1][x + 1] > 0)
					// 	tmp = d->hmap[y + 1][x + 1];
					if (tmp > 0)
					{
						d->hmap[y][x] = tmp + 1;
						z--;
					}
				}	
				x++;
			}
			y++;
		}
	}
}

void	enemy_presence(t_d *d, int y, int x, int l) //official
{
	printf("%d, %d\n", y, x);
	if (x < 0 || y < 0 || y > (d->my - 1) || x > (d->mx - 1) || (l > 0 && d->hmap[y][x] == l))//jotta vois käyttää kaikkia kutsuja tarvitsee kontrollin että onko jo täytetty
		return ;

	if (d->map[y][x] == d->e)
		d->hmap[y][x] = -1;
	else if ((d->map[y][x] != d->e) && (d->hmap[y][x] == 0 || (l < d->hmap[y][x])))
		d->hmap[y][x] = l;
	{
		enemy_presence(d, y - 1, x - 1, l + 1); 
		// enemy_presence(d, y, x - 1, l + 1);
		// enemy_presence(d, y + 1, x - 1, l + 1);
		enemy_presence(d, y + 1, x + 1, l + 1);
		// // enemy_presence(d, y + 1, x, l + 1);
	enemy_presence(d, y - 1, x + 1, l + 1);
	enemy_presence(d, y - 1, x, l + 1);
	enemy_presence(d, y, x + 1, l + 1);
	}
}

// void	enemy_presence(t_d *d, int y, int x, int e)
// {
// 	if (x < 0 || y < 0 || y > (d->my - 1) || x >= (d->mx - 1) || d->map[y][x] != e)
	// 	return ;
	// if (d->map[y][x] == e)
	// 	d->hmap[y][x] = -1 ;
	// else if (d->map[y][x] == e)
	// 	d->hmap[y][x] = 0;
	// enemy_presence(d, y - 1, x - 1, l + 1);
	// enemy_presence(d, y + 1, x - 1, l + 1);
	// enemy_presence(d, y, x - 1, l + 1);
	// // enemy_presence(d, y, x + 1, l + 1);
	// // enemy_presence(d, y + 1, x, l + 1);
	// // enemy_presence(d, y + 1, x + 1, l + 1);
	// enemy_presence(d, y - 1, x, l + 1);
	// enemy_presence(d, y - 1, x + 1, l + 1);
// }

void	make_heatmap(t_d *d)
{
	d->hmap = ft_inttab_malloc(d->my, d->mx); //if not yet
	max_out_hmap(d);
	map_to_heatmap(d);
}

int		choose_move(t_d *d)
{
	make_heatmap(d);
	if (play_pc(d) == -1)
		return (-1);
	return (1);
}
