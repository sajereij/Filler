/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:43:22 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/13 00:07:15 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/includes/libft.h"

typedef struct	s_data
{
	int		element;
	int		pnb;
	int		e;
	int		heat_score;
	char	**map;
	char	**pc;
	int		**hmap;
	int		my;
	int		mx;
	int		px;
	int		py;
	int		plx;
	int		pty;
	int		lmxx;
	int		lmxy;
	int		lmox;
	int		lmoy;
}				t_d;

int				print_move(t_d *d);
int				score_heat(t_d *d, int hmap_row, int hmap_col);
int				fit_pc(t_d *d, int token_row, int token_col, int *valid_move);
int				adjust_onto_map(int tmp);
void			try_pc(t_d *d, int cur_row, int cur_col, int *valid_move);
int				is_token(char **map, int check_row, int check_col, int token);
int				check_token_availability(t_d *d, int token, int y, int x);
int				find_tokens(t_d *d);

char			**trim_pc(t_d *d, int mx_row, int mx_col);
void			find_bottom_right_trim(t_d *d);
int				find_top_left(t_d *d);
int				adjust_pc(t_d *d);
int				play_pc(t_d *d);

void			fill_heatmap(t_d *d, int oppo_y, int oppo_x);
void			map_to_heatmap(t_d *d);
void			max_out_hmap(t_d *d);
void			make_heatmap(t_d *d);
int				choose_move(t_d *d);

void			first_moves(t_d *d);
void			save_dimensions(int element, int count, int value, t_d *d);
int				check_content(char *line, int max_cols, int cut);
int				trim_map(char *line);
char			**get_element(int rows, int cols, char *line, int element);
int				get_dim(t_d *d, char *line, int element);
int				get_data(t_d *d);
int				free_parts(t_d *d);
int				print_errors(int ret);
int				set_player(t_d *d);
void			clear_struct(t_d *d);
void			init_struct(t_d *d);

#endif
