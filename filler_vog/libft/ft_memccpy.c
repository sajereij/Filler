/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:10:33 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:49:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pds;
	unsigned char	*psr;
	size_t			i;

	i = 0;
	pds = (unsigned char *)dst;
	psr = (unsigned char *)src;
	while (i < n)
	{
		pds[i] = psr[i];
		if (pds[i] == (unsigned char)c)
			return ((void *)pds + i + 1);
		i++;
	}
	return (NULL);
}
