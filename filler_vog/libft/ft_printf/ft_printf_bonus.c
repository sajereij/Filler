/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:13:34 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 20:58:15 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Here are the added bonuses fd {#fd} and colors {CID}.
**	To add the printed color characters to final ret-value change line 34 to
**	i->pri += ft_putstr_ret_fd(code[ci], i->fd)
*/

#include "../includes/ft_printf.h"
#include "../includes/colors.h"

void	print_settings(const char *s, t_index *i, va_list ap)
{
	int ci;
	int	match;

	ci = -1;
	match = 0;
	if (ft_strnequ(s, "#FD", 3) == 1)
	{
		i->fd = va_arg(ap, int);
		match = 1;
	}
	else if (s[0] >= 'A' && s[0] <= 'Y')
		while (g_color[++ci] != NULL)
			if (ft_strnequ(s, g_color[ci], 3) == 1)
			{
				ft_putstr_fd(g_code[ci], i->fd);
				match = 1;
			}
	if (match == 0)
	{
		write(i->fd, s - 1, 5);
		i->pri += 5;
	}
	i->len += 5;
}
