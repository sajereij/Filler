/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 11:23:54 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 02:39:42 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_bigintlen(__int128_t n, int base)
{
	int c;

	c = 0;
	if (n == 0)
		c = 1;
	if (n <= -1)
		c = c + 1;
	while (n != 0)
	{
		n /= base;
		c++;
	}
	return (c);
}
