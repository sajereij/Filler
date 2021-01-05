/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:38:36 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/27 20:30:21 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_token(char **map, int check_row, int check_col, int token)
{
	if ((map[check_row][check_col] == token) \
		|| (map[check_row][check_col] == token + 32))
		return (1);
	return (0);
}

int		check_token_availability(t_d *d, int token, int y, int x)
{
	if (((x > 0) && (is_token(d->map, y, x - 1, token))) \
		&& ((x < d->mx) && (is_token(d->map, y, x + 1, token))) \
		&& ((y > 0) && (x > 0) && (is_token(d->map, y - 1, x - 1, token))) \
		&& ((y < (d->my - 1)) && (x < d->mx) \
			&& (is_token(d->map, y + 1, x + 1, token))) \
		&& ((y < (d->my - 1)) && (x > 0) \
			&& (is_token(d->map, y + 1, x - 1, token))) \
		&& ((y > 0) && (x < d->mx) \
			&& (is_token(d->map, y - 1, x + 1, token))) \
		&& ((y < (d->my - 1)) && (is_token(d->map, y + 1, x, token))) \
		&& ((y > 0) && (is_token(d->map, y - 1, x, token))))
		return (0);
	return (1);
}

int		find_tokens(t_d *d)
{
	int y;
	int x;
	int token;
	int	max;
	int	valid_move;

	valid_move = 0;
	token = (d->pnb == 1) ? 'O' : 'X';
	max = d->mx > d->my ? d->mx : d->my;
	d->heat_score = (d->px * d->py) * max;
	y = -1;
	while (++y < d->my)
	{
		x = -1;
		while (++x < d->mx)
		{
			if ((d->map[y][x] == token || d->map[y][x] == token + 32) \
			&& (check_token_availability(d, token, y, x)) == 1)
				try_pc(d, y - d->py + 1, x - d->px + 1, &valid_move);
		}
	}
	return (valid_move);
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
	if (adjust_pc(d) < 0)
		return (-3);
	if (d->py > d->my || d->px > d->mx)
		return (-2);
	if (find_tokens(d))
		return (print_move(d));
	return (-1);
}
