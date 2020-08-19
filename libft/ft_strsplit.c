/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:10:53 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/05 16:48:20 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_make_strings(char c, char **end)
{
	size_t	i;
	size_t	j;
	char	*fresh;

	i = 0;
	j = 0;
	while (**end == c)
		*end = *end + 1;
	while (end[0][i] != c && end[0][i] != '\0')
		i++;
	if (!(fresh = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	while (**end != c && **end != '\0')
	{
		fresh[j] = **end;
		j++;
		*end = *end + 1;
	}
	fresh[j] = '\0';
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**far;
	size_t	w;
	size_t	l;
	char	*end;

	l = 0;
	w = ft_count_words(s, c);
	end = (char *)s;
	if (!(far = (char **)malloc((w + 1) * sizeof(char *))))
		return (0);
	while (l < w)
	{
		far[l] = ft_make_strings(c, &end);
		l++;
	}
	far[l] = NULL;
	return (far);
}
