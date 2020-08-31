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

void	print_struct(t_d *d) //fd
{
	printf("%d pnb\n", d->pnb);
	printf("%d my\n", d->my);
	printf("%d mx\n", d->mx);
	printf("%d py\n", d->py);
	printf("%d px\n", d->px);
	printf("%d lmx col\n", d->lmxx);
	printf("%d lmx row\n", d->lmxy);
	printf("%d lmo col\n", d->lmox);
	printf("%d lmo row\n", d->lmoy);
}

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

char	**get_element(int rows, int cols, char *line, int element)
{
	int		i;
	char	**tmp;

	i = -1;
	// printf("SATA JÄNISTÄ!!!\n");
	if(!(tmp = (char **)malloc((rows + 1) * sizeof(char *))))
		return (NULL);
	while (++i < rows)
	{
		get_next_line(0, &line);
		if(!(tmp[i] = (char *)malloc((cols + 1) * sizeof(char))))
			return (NULL);
		line += (element == 'm') ? 4 : 0;
		ft_strcpy(tmp[i], line);
	}
	tmp[i] = NULL;
//	ft_strarr_print(tmp);
	return (tmp);
}

void	get_dim(t_d *d, char *line, int element)
{
	int	tmp;
	
	while (ft_isdigit(*line) == 0 && *line)
		line++;
	tmp = ft_atoi((const char *)line);
	(element == 'm') ? (d->my = tmp) : (d->py = tmp);
	while (ft_isdigit(*line) == 1 && *line)
		line++;
	tmp = ft_atoi((const char *)line);
	(element == 'm') ? (d->mx = tmp) : (d->px = tmp);
}

void	set_player(t_d *d)
{
	char *line;
	
	get_next_line(0, &line);
	if (ft_strstr(line, "sreijola") != NULL) 
		d->pnb = ft_atoi(ft_strchr((char *)line, 'p') + 1);
}

void	init_struct(t_d *d)
{
	d->fd = 1;
	d->pnb = 1;
	d->my = 0;
	d->mx = 0;
	d->py = 0;
	d->px = 0;
	d->lmxx = 0;
	d->lmxy = 0;
	d->lmox = 0;
	d->lmoy = 0;
	d->plx = 0;
	d->pty = 0;
	d->heat_score = 0;
}

void	get_data(t_d *d)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strnequ(line, "Plateau", 7))
		{
			get_dim(d, line, 'm');
			get_next_line(0, &line);
			d->map = get_element(d->my, d->mx, line, 'm');
			first_moves(d);
//			ft_strarr_print_fd(d->map, d->fd);
		}
		else if (ft_strnequ(line, "Piece", 5))
		{
			get_dim(d, line, 'p');
			d->pc = get_element(d->py, d->px, line, 'p');
//			ft_strarr_print_fd(d->pc, d->fd);
			break;
		}
		else
			ft_strdel(&line);
	}
}
