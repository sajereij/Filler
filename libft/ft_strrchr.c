/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 01:11:39 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/04 15:06:28 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	while (*s != c && len > 0)
	{
		s--;
		len--;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
