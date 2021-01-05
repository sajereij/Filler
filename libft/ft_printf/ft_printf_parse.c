/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:54:45 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_distance(char *p)
{
	int i;

	i = 0;
	while (p[i] != 's' && p[i] != 'c' && p[i] != 'p' && p[i] != 'i' \
		&& p[i] != 'd' && p[i] != 'f' && p[i] != 'o' && p[i] != 'u' \
		&& p[i] != 'x' && p[i] != 'X' && p[i] != '%')
		i++;
	return (i);
}

int		unpack_type(const char *f, va_list ap, t_ph *fact)
{
	int		lf;

	init_structp(fact);
	if (fill_struct((char *)f, fact) > 1)
		return (-1);
	lf = find_distance((char *)f);
	fact->type = f[lf];
	if (f[lf] == '%')
	{
		fact->out = ft_strdup("%");
		fact->per = 1;
	}
	else if (f[lf] == 'p')
		(type_p(va_arg(ap, unsigned long), fact));
	else if (f[lf] == 'c')
		(type_c(va_arg(ap, int), fact));
	else if (f[lf] == 's')
		(type_s(va_arg(ap, char *), fact));
	else if (f[lf] == 'i' || f[lf] == 'd')
		(type_id(ap, fact));
	else if (f[lf] == 'u' || f[lf] == 'o' || f[lf] == 'x' || f[lf] == 'X')
		(type_ouxx(f[lf], ap, fact));
	else if (f[lf] == 'f')
		(type_f(ap, fact));
	return (0);
}
