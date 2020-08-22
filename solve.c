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

void	ft_print_intarr(int **arr, int maxr, int maxc) //fd
{
	int i;
	int	j;

	i = -1;
	while(++i < maxr)
	{
		j = 0;
		while(j < maxc)
		{
			printf("%3i", arr[i][j]);
			j++;
		}
		printf("\n");
	}
}

int		**ft_malloc_inttab(int rows, int cols)
{
	int		**tmp;
	int		i;

	i = -1;
	if(!(tmp = (int **)malloc((rows) * sizeof(int *))))
		return (NULL);
	while (++i < rows)
	{
		if(!(tmp[i] = (int *)malloc((cols) * sizeof(int))))
			return (NULL);
	}
	return (tmp);
}

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

void	fill_map(t_d *d, int y, int x, int l) //b
{
	if ((d->map[y][x] != d->e) && (d->hmap[y][x] == 0 || (l <= d->hmap[y][x])))
	{
		d->hmap[y][x] = l;
	}
	if (d->map[y][x] == d->e)
		d->hmap[y][x] = -1;
}

int		ft_abs(int nb)
{
	return (nb = (nb < 0) ? -nb : nb);
}

void	fill_square(t_d *d, int y, int x)
{
	int	i;
	int	j;
	int l;
	
	j = 0;
	while (j < d->my)
	{
		i = 0;
		while (i < d->mx)
		{
			l = ft_abs(i - x) > ft_abs(j - y) ? ft_abs(i - x) : ft_abs(j - y);
			if ((d->hmap[j][i]) > l)
				d->hmap[j][i] = l;
			i++;
		}
		j++;
	}
}

void	ft_ca_maptoia_hmap(t_d *d)
{
	int	y;
	int	x;
	
	y = 0;
	d->e = (d->pnb == 1) ? 'X' : 'O';
	while (y < d->my)
	{
		x = 0;
		while (x < d->mx)
		{
			if(d->map[y][x] == d->e)
			{
				fill_square(d, y, x);
				//epp(d, y, x, 0);
				// eppp(d, y, x, 0);
//				enemy_presence(d, y, x, 0);
			}
			++x;
		}
		y++;
	}
	//fill_zeros(d);
	ft_print_intarr(d->hmap, d->my, d->mx);
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
			if ((d->hmap[y][x] == 0)) // || ((l <= d->hmap[y][x])))// && (y + 1 < zo)))
				tmp += 1;
			x++;
		}
		y++;
	}
	return (tmp);
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

// void	eppp(t_d *d, int y, int x, int l)
// {
// 	if (x < 0 || y < 0 || y > (d->my - 1) || x > (d->mx - 1))
// 		return ;
// 	if (d->map[y][x] == d->e)
// 		d->hmap[y][x] = -1;
// 	else if ((d->map[y][x] != d->e) && (d->hmap[y][x] == 0 || (l < d->hmap[y][x])))
// 		d->hmap[y][x] = l;
// 	eppp(d, y - 1, x, l + 1);
// 	eppp(d, y - 1, x + 1, l + 1);
// 	eppp(d, y - 1, x, l + 1);
// 	eppp(d, y + 2, x + 2, l + 1);
// }

void	epp(t_d *d, int y, int x, int l)
{
	if (x < 0 || y < 0 || y > (d->my - 1) || x > (d->mx - 1))
		return ;
	if (d->map[y][x] == d->e)
		d->hmap[y][x] = -1;
	else if ((d->map[y][x] != d->e) && (d->hmap[y][x] == 0 || (l < d->hmap[y][x])))
		d->hmap[y][x] = l;
	// epp(d, y - 1, x, l + 1);
	// epp(d, y - 1, x + 1, l + 1);
	epp(d, y, x + 1, l + 1);
	epp(d, y + 1, x, l + 1);
	epp(d, y + 1, x + 1, l + 1);
	epp(d, y + 2, x - 2, l + 1);
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

int		enemy_presence_max(t_d *d, int y, int x)
{
	int	p;
	int	e;

	p = 0;
	e = (d->pnb == 1) ? 'X' : 'O';
	if (d->map[y][x] == e)
		return (0);
	p += (x > 0 && d->map[y][x - 1] == e) ? 1 : 0;
	p += (x < d->mx && d->map[y][x + 1] == e) ? 1 : 0;
	p += (y > 0 && x > 0 && d->map[y - 1][x - 1] == e) ? 1 : 0;
	p += (y < (d->my - 1) && x < d->mx && d->map[y + 1][x + 1] == e) ? 1 : 0;
	p += (y < (d->my - 1) && x > 0 && d->map[y + 1][x - 1] == e) ? 1 : 0;
	p += (y > 0 && x < d->mx && d->map[y - 1][x + 1] == e) ? 1 : 0;
	p += (y < (d->my - 1) && d->map[y + 1][x] == e) ? 1 : 0;
	p += (y > 0 && d->map[y - 1][x] == e) ? 1 : 0;
	return (p);
}



void	make_heatmap(t_d *d)
{
	d->hmap = ft_malloc_inttab(d->my, d->mx);
	max_out_hmap(d);
	ft_ca_maptoia_hmap(d);
}

void	choose_move(t_d *d)
{
	make_heatmap(d);
}
