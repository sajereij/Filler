/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 23:21:13 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:49:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_ulltoa_base(unsigned long value, int base)
{
	char	*out;
	char	hex_digits[16];
	int		i;

	ft_strcpy(hex_digits, "0123456789abcdef");
	i = ft_ulllen(value, base);
	out = ft_memalloc(sizeof(char) * (i + 1));
	out[i] = '\0';
	if (value == 0)
		out[0] = '0';
	while (value != 0)
	{
		out[--i] = hex_digits[value % base];
		value /= base;
	}
	return (out);
}
