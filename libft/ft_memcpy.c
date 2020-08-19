/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:09:41 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/03 15:44:39 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pds;
	unsigned char *psr;

	pds = (unsigned char *)dst;
	psr = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (n == 0)
		return (dst);
	while (n > 0)
	{
		pds[n - 1] = psr[n - 1];
		n--;
	}
	return (dst);
}
