/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:05:24 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/28 03:02:39 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		free_parts(t_d *d)
{
	if (d->pc)
		ft_strarr_free(d->pc);
	if (d->map)
		ft_strarr_free(d->map);
	if (d->hmap)
		ft_intarr_free(d->hmap, d->my);
	return (0);
}

int		print_errors(int ret)
{
	if (ret == -1)
		write(2, "No valid moveS!\n", 16);
	if (ret == -2)
		write(2, "Piece bigger than maP!\n", 23);
	if (ret == -3)
		write(2, "Empty pC!\n", 10);
	if (ret == -4)
		write(2, "Map is invaliD!\n", 16);
	if (ret == -5)
		write(2, "Piece is invaliD!\n", 18);
	if (ret == -6)
		write(2, "Invalid dimensions for maP!\n", 28);
	if (ret == -7)
		write(2, "Invalid dimensions for piecE!\n", 30);
	if (ret == -8)
		write(2, "Wrong player or invalid player numbeR!\n", 39);
	if (ret == -9)
		write(2, "Failed to read filE\n", 20);
	return (0);
}

int		set_player(t_d *d)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (-9);
	if (ft_strstr(line, "sreijola") != NULL)
	{
		d->pnb = ft_atoi(ft_strchr((char *)line, 'p') + 1);
		ft_strdel(&line);
		if (d->pnb != 1 && d->pnb != 2)
			return (-8);
	}
	else
	{
		ft_strdel(&line);
		return (-8);
	}
	return (1);
}

void	init_struct(t_d *d)
{
	d->element = 's';
	d->pnb = -1;
	d->my = -1;
	d->mx = -1;
	d->py = -1;
	d->px = -1;
	d->lmxx = 0;
	d->lmxy = 0;
	d->lmox = 0;
	d->lmoy = 0;
	d->plx = 0;
	d->pty = 0;
	d->heat_score = 0;
}

int		main(void)
{
	t_d		data;
	int		ret;

	init_struct(&data);
	if ((ret = set_player(&data)) < 0)
		return (print_errors(ret));
	while (1)
	{
		if ((ret = get_data(&data)) < 0)
			return (print_errors(ret));
		if ((ret = choose_move(&data)) < 0)
			return (print_errors(ret));
	}
	free_parts(&data);
	return (0);
}
