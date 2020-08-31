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

// void	basic_tupla(t_d *d)
// {
// 	int	cur_col;
// 	int	cur_row;
//	int tmp;
// 	cur_row = -1;
// 	while (++cur_row < d->py)
// 	{
// 		cur_col = -1;
// 		while (++cur_col < d->px)
// 			enemy_presence_max(d, enemy_y, enemy_x);
// 	}
// }

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

int		fit_pc(t_d *d, int e_row, int e_col, int *valid_move)
{
	int		pc_row;
	int		pc_col;
	int		token;
	int		over;
	
	pc_row = -1;
	token = (d->pnb == 1) ? 'O' : 'X';
	over = 0;
	while (++pc_row < d->py && (e_row + pc_row < d->my))
	{
		pc_col = -1;
		while (++pc_col < d->px && (e_col + pc_col < d->mx))
		{
//		printf("fit:%d %d\n", pc_row + e_row, pc_col + e_col);
			if (d->pc[pc_row][pc_col] == '*')
			{
				if (d->hmap[e_row + pc_row][e_col + pc_col] == 0)
					return (-1);
				if (d->map[e_row + pc_row][e_col + pc_col] == token \
					|| d->map[e_row + pc_row][e_col + pc_col] == token + 32)
					over++;
				if (over > 1)
					return (-1);
			}
		}
	}
//	printf("%d\n", over);
	if (over != 1)
		return (-1);
	*valid_move = 1;
	return (1);
}

// int			check_center(t_d *d, int cur_ans_row, int cur_ans_col)
// {
// 	int		center_row;
// 	int		center_col;
// 	center_row = d->my / 2;
// 	center_col = d->my / 2; 
// 	if (e = 'X')
// 	{
	
int			adjust_row_col_onto_map(int tmp)
{
	return((tmp < 0) ? 0 : tmp);
}

void		try_pc(t_d *d, int cur_row, int cur_col, int *valid_move)
{
	int	pc_row;
	int	pc_col;
	int tmp;

	cur_row = adjust_row_col_onto_map(cur_row);
	cur_col = adjust_row_col_onto_map(cur_col);
	pc_row = -1;
	while (((++pc_row + cur_row) < d->my - d->py + 1) && (pc_row < d->py))
	{
		pc_col = -1;
		while ((++pc_col + cur_col < d->mx - d->px + 1) && pc_col < d->px)
		{
			if (fit_pc(d, pc_row + cur_row, pc_col + cur_col, valid_move) == 1)
			{	
				if ((tmp = score_heat(d, pc_row + cur_row, pc_col + cur_col)) <= d->heat_score) \
					//&& tmp == d->heat_score && check_center(d, ((pc_row + cur_row) - d->pty), ((pc_col + cur_col) - d->plx)) == 1)
				{
					d->heat_score = tmp;
					(d->pnb == 1) ? (d->lmox = ((pc_col + cur_col) - d->plx)) \
						: (d->lmxx = ((pc_col + cur_col) - d->plx));
					(d->pnb == 1) ? (d->lmoy = ((pc_row + cur_row) - d->pty)) \
						: (d->lmxy = ((pc_row + cur_row) - d->pty));
					// printf("FITS SO HEAT:%d: %d %d\n", d->heat_score, pc_row + cur_row, pc_col + cur_col);
					// printf("%d %d\n", d->lmoy, d->lmox);
				}
			}
		}
	}
}

int		is_token(char **map, int check_row, int check_col, int token)
{
	if ((map[check_row][check_col] == token) \
		|| (map[check_row][check_col] == token + 32))
		return (1);
	return(0);
}

int		check_token_availability(t_d *d, int token, int y, int x)
{
	if (((x > 0) && (is_token(d->map, y, x - 1, token))) \
		&& ((x < d->mx) && (is_token(d->map, y, x + 1, token))) \
		&& ((y > 0) && (x > 0) && (is_token(d->map, y - 1, x - 1, token))) \
		&& ((y < (d->my - 1)) && (x < d->mx) && (is_token(d->map, y + 1, x + 1, token))) \
		&& ((y < (d->my - 1)) && (x > 0) && (is_token(d->map, y + 1, x - 1, token))) \
		&& ((y > 0) && (x < d->mx) && (is_token(d->map, y - 1, x + 1, token))) \
		&& ((y < (d->my - 1)) && (is_token(d->map, y + 1, x, token))) \
		&& ((y > 0) && (is_token(d->map, y - 1, x, token))))
		return(0);
	return (1);
}

int		find_tokens(t_d *d)
{
	int y;
	int x;
	int token;
	int	tmp;
	int	valid_move;
	
	valid_move = 0;
	token = (d->pnb == 1) ? 'O' : 'X';
	tmp = d->mx > d->my ? d->mx : d->my;
	d->heat_score = (d->px * d->py) * tmp;
	y = -1;
	while (++y < d->my)
	{
		x = -1;
		while (++x < d->mx)
		{
			if ((d->map[y][x] == token || d->map[y][x] == token + 32) \
				&& (check_token_availability(d, token, y, x)) == 1)
			{
//				printf("\nTOKEN:%d %d\n\n", y, x);
				try_pc(d, y - d->py + 1, x - d->px + 1, &valid_move);
			}
		}
	}
	if (valid_move == 0) //todennäköisesti turha, koska antaa edelliset arvot joka tapauksessa ja ne menevät väärin.
		return(0);
//	printf("%d\n", d->heat_score);
	return (1);
}

int		print_move(t_d *d)
{
	d->pnb == 1 ? ft_putnbr(d->lmoy) : ft_putnbr(d->lmxy);
	ft_putchar(' ');
	d->pnb == 1 ? ft_putnbr(d->lmox) : ft_putnbr(d->lmxx);
	ft_putchar('\n');
	return (1);
}

int		play_pc(t_d *d)
{
	adjust_pc(d);
	if (d->py > d->my || d->px > d->mx)
		return(-2);
	if (find_tokens(d))
		return(print_move(d));
	return (-1);
	// d->pnb == 1 ? printf("%d %d\n", d->lmoy, d->lmox) : printf("%d %d\n", d->lmxy, d->lmxx);
	// ft_arr_fr(d->map, d->my);
	// ft_arr_fr(d->pc, d->py);
}
