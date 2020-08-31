/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:43:22 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/19 15:43:22 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_data
{
	int		fd;
	int		pnb;
	int		e; //enemy
	int		heat_score;
	char	**map;
	char	**pc;
	int		**hmap;
	int		my;
	int		mx;
	int		px;
	int		py;
	int		plx; //left col
	int		pty; //top row
	int		lmxx;
	int		lmxy;
	int		lmox;
	int		lmoy;
}				t_d;

void	ft_strarr_print_fd(char **arr, int fd);
void	ft_print_strarr(char **arr);
void	ft_strarr_print(char **arr);
char	**ft_strarr_malloc(int rows, int cols);
void	ft_strarr_free(char **arr, int rows);

void	ft_intarr_print_fd(int **arr, int max_rows, int max_cols, int fd);
void	ft_intarr_print(int **arr, int max_rows, int max_cols);
int		**ft_inttab_malloc(int max_rows, int max_cols);



void	adjust_pc(t_d *d);
void	find_top_right(t_d *d);

int		ft_abs(int nb);

void	init_struct(t_d *d);
void	set_player(t_d *d);
void	get_data(t_d *d);
int		play_pc(t_d *d);
int		choose_move(t_d *d);

#endif
