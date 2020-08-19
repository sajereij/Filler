/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:12:16 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/05 17:26:00 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			pdst[n] = psrc[n];
	}
	return ((void *)pdst);
}
