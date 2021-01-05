/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fill_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:15:21 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_length(char *f, t_ph *p)
{
	int i;

	i = 0;
	p->leng_detected += 1;
	p->leng = *f;
	if ((f[i] == 'l' && f[i + 1] == 'l') || (f[i] == 'h' && f[i + 1] == 'h'))
	{
		p->leng = (*f) * 2;
		f++;
	}
	return (f);
}

char	*fill_prec(char *f, t_ph *p)
{
	p->dot = 1;
	p->pres = (ft_isdigit(*f)) ? ft_atoi(f) : 0;
	while (ft_isdigit(*f))
		f++;
	f--;
	return (f);
}

void	fill_flag(char c, t_ph *p)
{
	if (c == '-')
		p->minus = 1;
	if (c == '+')
		p->plus = 1;
	if (c == ' ')
		p->space = 1;
	if (c == '0')
		p->zero = 1;
	if (c == '#')
		p->tag = 1;
}

int		fill_struct(char *f, t_ph *p)
{
	while (*f != 's' && *f != 'c' && *f != 'p' && *f != 'i' && *f != 'd' \
		&& *f != '%' && *f != 'f' && *f != 'o' && *f != 'u' && *f != 'x' \
		&& *f != 'X' && *f != '\0' && p->leng_detected < 2)
	{
		while (*f == '-' || *f == '+' || *f == ' ' || *f == '0' || *f == '#')
		{
			fill_flag(*f, p);
			f++;
		}
		if (ft_isdigit(*f))
		{
			p->wid = ft_atoi(f);
			while (ft_isdigit(*f))
				f++;
			f--;
		}
		if (*f == '.')
			f = fill_prec(f + 1, p);
		if (*f == 'l' || *f == 'h' || *f == 'L')
			f = fill_length(f, p);
		f++;
	}
	p->wpdif = p->wid - p->pres;
	return (p->leng_detected);
}

void	init_structp(t_ph *p)
{
	p->sign = '+';
	p->dif = 0;
	p->zero = 0;
	p->plus = 0;
	p->minus = 0;
	p->space = 0;
	p->tag = 0;
	p->wid = 0;
	p->dot = 0;
	p->pres = 0;
	p->leng_detected = 0;
	p->leng = 0;
	p->type = 0;
	p->zos = 0;
	p->per = 0;
	p->per = 0;
	p->null = 0;
}
