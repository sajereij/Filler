/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:28:44 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:49:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int fre)
{
	char	*fr;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	fr = ft_memalloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(fr))
		return (0);
	while (s1[++i] != '\0')
		fr[i] = s1[i];
	while (s2[j] != '\0')
		fr[i++] = s2[j++];
	fr[i] = '\0';
	if (fre == 1 || fre == 3)
		free((char *)s1);
	if (fre == 2 || fre == 3)
		free((char *)s2);
	return (fr);
}
