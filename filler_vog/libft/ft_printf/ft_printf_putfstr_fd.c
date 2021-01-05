/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putfstr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:11:51 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putfstr_fd(char const *str, t_index *i)
{
	size_t ret;

	ret = 0;
	if (str)
	{
		while (str[ret] != '\0' && str[ret] != '%' \
		&& !(str[ret] == '{' && str[ret + 4] == '}'))
			ret++;
		write(i->fd, str, ret);
		i->len += ret;
	}
	return (ret);
}
