/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:23:41 by sreijola          #+#    #+#             */
/*   Updated: 2019/10/31 12:10:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fr;
	size_t	i;

	i = 0;
	if (!(fr = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	while (s[start] != '\0' && i < len)
	{
		fr[i] = s[start];
		start++;
		i++;
	}
	fr[i] = '\0';
	return (fr);
}
