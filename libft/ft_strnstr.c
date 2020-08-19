/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 01:21:14 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/04 19:08:24 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t nl;

	i = 0;
	nl = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack && i + nl <= len)
	{
		if (ft_strncmp(haystack, needle, nl) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
