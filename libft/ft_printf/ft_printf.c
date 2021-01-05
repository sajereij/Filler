/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:48:44 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_format(const char *s1, const char *s2)
{
	int	i;

	i = 1;
	while (s1[i] != '\0')
	{
		if (ft_strchr(s2, s1[i]) == NULL)
			return (0);
		if (s1[i] == 'i' || s1[i] == 's' || s1[i] == 'c' \
			|| s1[i] == 'p' || s1[i] == 'd' || s1[i] == 'f' \
			|| s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'x' \
			|| s1[i] == 'X' || s1[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		check_conversion(const char *fstr, va_list ap)
{
	int		ret;

	ret = check_format(fstr, " +-#.1234567890lhLcspdiouxXf%");
	if (ret == 0)
		va_arg(ap, void *);
	return (ret);
}

void	print_placeholder(const char *f, t_ph *p, t_index *i, va_list ap)
{
	i->len++;
	if (unpack_type(f + i->len, ap, p) < 0)
		return ;
	p->per == 0 ? edit_output(p) : 0;
	i->pri += (p->null == 1 && p->type == 'c') ? \
		null_c(p, i->fd) : ft_putstr_ret_fd(p->out, i->fd);
	free(p->out);
	while (p->per == 0 && f[i->len - 1] != 's' \
		&& f[i->len - 1] != 'c' && f[i->len - 1] != 'p' \
		&& f[i->len - 1] != 'i' && f[i->len - 1] != 'd' \
		&& f[i->len - 1] != 'f' && f[i->len - 1] != 'o' \
		&& f[i->len - 1] != 'u' \
		&& f[i->len - 1] != 'x' && f[i->len - 1] != 'X' \
		&& f[i->len] != '\0')
		++i->len;
	i->len += (p->per == 1) ? last_pct(f) : 0;
}

void	init_structi(t_index *i)
{
	i->len = 0;
	i->pri = 0;
	i->fd = 1;
}

int		ft_printf(const char *f, ...)
{
	t_index		i;
	t_ph		info;
	va_list		ap;

	va_start(ap, f);
	init_structi(&i);
	while (f[i.len] != '\0')
	{
		if (f[i.len] != '%' && f[i.len] != '\0')
		{
			i.pri += ft_putfstr_fd(f + i.len, &i);
			if (f[i.len] == '{' && f[i.len + 4] == '}')
				print_settings(f + (i.len + 1), &i, ap);
		}
		else if (f[i.len] == '%' && check_conversion(f + i.len, ap))
			print_placeholder(f, &info, &i, ap);
		else if (f[i.len] != '\0')
			i.len++;
	}
	va_end(ap);
	return (i.pri);
}
