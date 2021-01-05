/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:21:04 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:58:35 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_index
{
	int		pri;
	int		len;
	int		fd;
}				t_index;

typedef struct	s_ph
{
	int		sign;
	int		dif;
	int		zero;
	int		plus;
	int		minus;
	int		space;
	int		tag;
	int		wid;
	int		wpdif;
	int		dot;
	int		pres;
	int		leng_detected;
	int		leng;
	int		type;
	int		zos;
	int		per;
	int		null;
	char	*out;
}				t_ph;

int				last_pct(const char *f);
int				null_c(t_ph *p, int fd);

void			ft_sign_pos_fixer(t_ph *p, int len);
int				ft_zeroer(t_ph *p);
int				ft_widener(t_ph *p, int len);
int				ft_leftie(t_ph *p, int len);
int				ft_flagger(t_ph *p);
void			prec_s(t_ph *p, int len);
void			prec_diouxxp(t_ph *p, int len);
int				ft_preciser(t_ph *p, int len);
void			edit_output(t_ph *p);

void			ftype_zeroer(t_ph *p, char **out);
char			*ft_printf_ldtoa(long double n, int afterpoint, t_ph *p);

void			type_f(va_list ap, t_ph *p);
void			type_ouxx(char type, va_list ap, t_ph *p);
void			type_id(va_list ap, t_ph *p);
void			type_p(unsigned long ad, t_ph *p);
void			type_c(int c, t_ph *p);
void			type_s(char *s, t_ph *p);

int				find_distance(char *p);
char			*fill_length(char *f, t_ph *p);
char			*fill_prec(char *f, t_ph *p);
void			fill_flag(char c, t_ph *p);
int				fill_struct(char *f, t_ph *p);
void			init_structp(t_ph *p);
int				unpack_type(const char *f, va_list ap, t_ph *fact);

void			print_settings(const char *s, t_index *i, va_list ap);
int				ft_putfstr_fd(char const *str, t_index *i);

void			print_placeholder(const char *f, t_ph *p, \
									t_index *i, va_list ap);
int				check_format(const char *s1, const char *s2);
int				check_conversion(const char *fstr, va_list ap);
void			init_structi(t_index *i);
int				ft_printf(const char *f, ...);

#endif
