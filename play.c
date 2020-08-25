/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:38:36 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/20 21:38:36 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_arr_fr(char **arr, int rows)
{
	while (rows >= 0)
	{
		free(arr[rows]);
		rows--;
	}
	free(arr);
}

// void	basic_tupla(t_d *d)
// {
// 	int	cur_col;
// 	int	cur_row;
// //	int tmp;
	
// 	cur_row = -1;
// 	while (++cur_row < d->py)
// 	{
// 		cur_col = -1;
// 		while (++cur_col < d->px)
// 			enemy_presence_max(d, enemy_y, enemy_x);
// 	}
// }

void	ft_strarr_free(char **arr, int rows)
{
	while (rows > -1)
	{
		free(arr[rows]);
		rows--;
	}
	free(arr);
//	ft_print_strarr(arr);
}

char	**ft_strarr_trim(t_d *d, int last_row, int last_col)
{
	int		i;
	char	**tmp;

	i = -1;
	if(!(tmp = (char **)malloc(((last_row - d->pty + 2) * sizeof(char *)))))
		return (NULL);
	while (++i + d->pty <= last_row)
		tmp[i] = ft_strsub(d->pc[d->pty + i], d->plx, last_col - d->plx + 1);	
	tmp[i] = NULL;
	ft_strarr_free(d->pc, d->py);
	d->py -= (d->pty) + (d->py - last_row - 1);
	d->px = ft_strlen(tmp[0]);
	printf("new dim: y %d x %d\n", d->py, d->px);
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
		{
			if (d->pc[cur_row][cur_col] == '*')
			{
				pc_endy = (cur_row > pc_endy) ? cur_row : pc_endy;
				pc_endx = (cur_col > pc_endx) ? cur_col : pc_endx;
			}
		}
	}
	// printf("bottom-right: %d, %d\n", pc_endy, pc_endx);
	d->pc = ft_strarr_trim(d, pc_endy,  pc_endx);
	ft_print_strarr(d->pc);
}

void	find_top_left(t_d *d)
{
	int	cur_col;
	int	cur_row;

	cur_row = -1;
	d->plx = d->px;
	d->pty = d->py;
	ft_print_strarr(d->pc);
	while (++cur_row < d->py)
	{
		cur_col = -1;
		while (++cur_col < d->px)
		{
			if (d->pc[cur_row][cur_col] == '*')
			{
				d->pty = (cur_row < d->pty) ? cur_row : d->pty;
				d->plx = (cur_col < d->plx) ? cur_col : d->plx;
			}
		}
	}
		// printf("top-left: %d, %d\n", d->pty, d->plx);
}

int		sum_heat(t_d *d, int map_row, int map_col)
{
	int		pc_row;
	int		pc_col;
	int		sum;
	
	pc_col = -1;
	while (++pc_row < d->py)
	{
		pc_col = -1;
		while (++pc_col < d->px)
		{
			if (d->pc[pc_row][pc_col] == '*')
			{
				sum = 1;
				return (sum);
			}
		}
	}
	map_col = map_row + map_col;
	map_row = map_row + map_row;
	return (0);
}

void	put_pc(t_d *d)
{
	int y;
	int x;
	
	y = -1;
	while (++y < d->my)
	{
		x = -1;
		while (++x < d->mx)
		{
			if ((d->hmap[y][x] == 0) && (!(((x > 0) && (d->hmap[y][x - 1] == 0)) \
			&& ((x < d->mx) && (d->hmap[y][x + 1] == 0)) \
			&& ((y > 0) && (x > 0)&& (d->hmap[y - 1][x - 1] == 0)) \
			&& ((y < (d->my - 1)) && (x < d->mx) && (d->hmap[y + 1][x + 1] == 0)) \
			&& ((y < (d->my - 1)) && (x > 0) && (d->hmap[y + 1][x - 1] == 0))\
			&& ((y > 0) && (x < d->mx) && (d->hmap[y - 1][x + 1] == 0)) \
			&& ((y < (d->my - 1)) && (d->hmap[y + 1][x] == 0)) \
			&& ((y > 0) && (d->hmap[y - 1][x]) == 0))))
				sum_heat(d, y, x);
		}
	}
}

void	play_pc(t_d *d)
{
	find_top_left(d);
	find_bottom_right_trim(d);
//	put_pc(d);
	d->pnb == 1 ? printf("%d %d\n", d->lmoy, d->lmox) : printf("%d %d\n", d->lmxy, d->lmxx);
	// ft_arr_fr(d->map, d->my);
	// ft_arr_fr(d->pc, d->py);
}
