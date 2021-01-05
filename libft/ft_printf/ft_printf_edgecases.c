/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_edgecases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:14:25 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		last_pct(const char *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%' && f[i + 1] == '%')
			return (1);
		else
		{
			if (f[i] == '%')
				j = i;
		}
		i++;
	}
	return (j);
}

int		null_c(t_ph *p, int fd)
{
	int	len;

	len = ft_strlen(p->out);
	if (p->minus == 0 && len > 0)
	{
		p->out[len - 1] = '\0';
		ft_putstr_fd(p->out, fd);
	}
	ft_putchar_fd('\0', fd);
	if (p->minus == 1 && len > 0)
	{
		p->out[len - 1] = '\0';
		ft_putstr_fd(p->out, fd);
	}
	len = ft_strlen(p->out);
	return (len + 1);
}
