/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_csp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:49:42 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Here are the converters for p, s, c. If %p and NULL, on ubuntu should
**	duplicate (nil), on MAC then 0x0. change lines 26-27 to:
** 	p->out = ft_strdup("(nil)");
*/
#include "../includes/ft_printf.h"

void	type_p(unsigned long ad, t_ph *p)
{
	if (ad)
		p->out = ft_ulltoa_base(ad, 16);
	else
	{
		p->out = ft_strdup("0");
		p->sign = '0';
	}
}

void	type_c(int c, t_ph *p)
{
	p->out = ft_memalloc(2 * sizeof(char));
	(c == '\0') ? p->null = 1 : 0;
	p->out[0] = c;
	p->out[1] = '\0';
}

void	type_s(char *s, t_ph *p)
{
	if (s)
		p->out = ft_strdup(s);
	else
	{
		p->out = ft_strdup("(null)");
		p->null = 1;
	}
}
