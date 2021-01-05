/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:13:15 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/28 03:12:09 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_moves(t_d *d)
{
	int i;
	int	j;

	i = -1;
	while (d->map[++i] != NULL)
	{
		j = 0;
		while (d->map[i][j] != '\0')
		{
			if (d->map[i][j] == 'X' || d->map[i][j] == 'x')
			{
				d->lmxx = j;
				d->lmxy = i;
			}
			if (d->map[i][j] == 'O' || d->map[i][j] == 'o')
			{
				d->lmox = j;
				d->lmoy = i;
			}
			j++;
		}
	}
}

void	save_dimensions(int element, int count, int value, t_d *d)
{
	if (count == 2)
	{
		if (element == 'm')
			d->mx = value;
		else
			d->px = value;
	}
	if (count == 1)
	{
		if (element == 'm')
			d->my = value;
		else
			d->py = value;
	}
}

int		get_dim(t_d *d, char *line, int element)
{
	int	tmp;
	int	count;

	count = 1;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			tmp = ft_atoi((const char *)line);
			while (ft_isdigit(*line) == 1 && *line)
				line++;
			if (count < 3)
				save_dimensions(element, count, tmp, d);
			count++;
		}
		line++;
	}
	if ((element == 'm' && (d->my < 0 || d->mx < 0)) \
	|| (element == 'p' && (d->px < 0 || d->py < 0)) || count > 3)
		return (-1);
	return (1);
}

int		get_data(t_d *d)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strnequ(line, "Plateau", 7))
		{
			if (get_dim(d, line, 'm') < 0)
				return (-6);
			get_next_line(0, &line);
			if ((d->map = get_element(d->my, d->mx, line, 'm')) == NULL)
				return (-4);
			first_moves(d);
		}
		else if (ft_strnequ(line, "Piece", 5))
		{
			if (get_dim(d, line, 'p') < 0)
				return (-7);
			if ((d->pc = get_element(d->py, d->px, line, 'p')) == NULL)
				return (-5);
			break ;
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
