/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:33:08 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/05 15:30:14 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_trimend(char *s, int i)
{
	char	*trim;

	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if (!(trim = (char *)malloc((i + 2) * sizeof(char))))
		return (NULL);
	trim[i + 1] = '\0';
	while (i >= 0)
	{
		trim[i] = s[i];
		i--;
	}
	return (trim);
}

char		*ft_strtrim(char const *s)
{
	char	*lean;
	char	*end;
	int		i;
	int		e;

	i = 0;
	e = 0;
	if (!s)
		return (NULL);
	end = (char *)s;
	if (!(end = (char *)malloc((ft_strlen(s)) * sizeof(char))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		end[e] = s[i];
		i++;
		e++;
	}
	lean = ft_trimend(end, e);
	return (lean);
}
