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

void	ft_print_strarr(char **arr) //fd
{
	int i;
	
	i = -1;
	while (arr[++i] != NULL)
		printf("%s\n", arr[i]);
	printf("\n");
	
}

void	prev_move(t_d *d, char *line)
{
	int	tmp;
	
	while (ft_isdigit(*line) == 0 && *line)
	{
		d->prev_turn = (*line == 'X') ? 'X' : 'O';
		line++;
	}
	tmp = ft_atoi((const char *)line);
	(d->prev_turn == 'X') ? (d->lmxy = tmp) : (d->lmoy = tmp);
	while (ft_isdigit(*line) == 1 && *line)
		line++;
	tmp = ft_atoi((const char *)line);
	(d->prev_turn == 'X') ? (d->lmxx = tmp) : (d->lmox = tmp);
}

void	first_moves(t_d *d)
{
	int i;
	int	j;
	
	i = -1;
	j = 0;
	while (d->map[++i] != NULL)
	{
		// printf("!!!!!WC-ANKKA!!!!!\n");
		while (d->map[i][j] != '\0')
		{
			// printf("!!!!!SAUNASORSA!!!!!\n");
			if (d->map[i][j] == 'X')
			{
				d->lmxx = j;
				d->lmxy = i;
			}
			if (d->map[i][j] == 'O')
			{
				d->lmox = j;
				d->lmoy = i;
			}
			j++;
		}
		j = 0;
	}
}

char	**get_element(int rows, int cols, char *line, int element)
{
	int		i;
	char	**tmp;

	i = -1;
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

void	set_player(t_d *d, char *line)
{
	if (ft_strstr(line, "sreijola") != NULL) 
		d->pnb = ft_atoi(ft_strchr((char *)line, 'p') + 1);
}

void	init_struct(t_d *d)
{
	d->fd = 0;
	d->pnb = 0;
	d->prev_turn = 0;
	d->my = 0;
	d->mx = 0;
	d->py = 0;
	d->px = 0;
	d->lmxx = 0;
	d->lmxy = 0;
	d->lmox = 0;
	d->lmoy = 0;
}

void	get_data(t_d *d)
{
	char	*line;
	char	*tmp;

	while (get_next_line(d->fd, &line) != 0)
	{
		tmp = line;
		if (ft_strnequ(line, "$$$", 3))
			set_player(d, line);
		else if (ft_strnequ(line, "Plateau", 7))
		{
			get_dim(d, line, 'm');
			get_next_line(d->fd, &line);
			d->map = get_element(d->my, d->mx, line, 'm');
			first_moves(d);
		}
		else if (ft_strnequ(line, "Piece", 5))
		{
			get_dim(d, line, 'p');
			d->pc = get_element(d->py, d->px, line, 'p');
		}
		else if (ft_strnequ(line, "Got", 3))
			prev_move(d, line);
		//ft_strclr(line);
		free(tmp);
	}
	// ft_print_strarr(d->map);
	// ft_print_strarr(d->pc);
	// print_struct(d);
}
