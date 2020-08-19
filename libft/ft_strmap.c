/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:25:10 by sreijola          #+#    #+#             */
/*   Updated: 2019/10/31 12:09:09 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fr;

	i = 0;
	if (!(fr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	while (s[i] != '\0')
	{
		fr[i] = f(s[i]);
		i++;
	}
	fr[i] = '\0';
	return (fr);
}
