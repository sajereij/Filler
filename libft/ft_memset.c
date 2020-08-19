/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:14 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/04 11:58:06 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char m;

	ptr = (unsigned char *)b;
	m = (unsigned char)c;
	while (len > 0)
	{
		ptr[len - 1] = m;
		len--;
	}
	return (b);
}
