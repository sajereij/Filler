/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:13:15 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/19 17:13:15 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void	get_dim_p(t_d *d, char *line)
{
	while (*line < '0' && *line > '9')
		line++;
	d->py = ft_atoi(*line);
	while (*line >= '0' && *line <= '9')
		line++;
	d->px = ft_atoi(*line)
}

void	get_dim_m(t_d *d, char *line)
{
	while (*line < '0' && *line > '9')
		line++;
	d->my = ft_atoi(*line);
	while (*line >= '0' && *line <= '9')
		line++;
	d->mx = ft_atoi(*line)
}

void	init_struct(t_d *d)
{
	d->fd = 0;
	mx = 0;
	my = 0;
	px = 0;
	py = 0;
}

void	get_data()
{
	t_d		data;
	char	*line;

	init_struct(&data);
	while (get_next_line(data.fd, &line) != 0)
	{
		if (ft_strncmp(line, "Plateau", 7))
		{
			get_dim_m(&data, line);
			get_next_line(data.fd, &line);
			get_map(&data, line);
		}
		ft_strclr(line);
		else if (ft_strncmp(line, "Piece", 5))
		{
			get_dim_p(&data, line);
			get_next_line(data.fd, &line);
			get_pc(&data, line);
		}
	}
	return (0);
}
