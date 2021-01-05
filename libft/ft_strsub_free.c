/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:54:43 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/27 20:55:58 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len, int fre)
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
	if (fre == 1)
		free(s);
	return (fr);
}
