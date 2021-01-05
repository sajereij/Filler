/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strround_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:48:59 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:49:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strround_up(char *s, int len, int zero)
{
	int	i;

	i = len;
	if (s[len] >= '5')
	{
		if (s[--len] == '9')
			while (s[len] == '9' || s[len] == '.')
			{
				if ((len == 0 && s[len] == '9') \
				|| (zero == '0' && len == 0 && s[len] == '.'))
				{
					if (len == 0 && s[len] == '9')
						s[len--] = '0';
					s[i] = '\0';
					return (ft_strjoin_free("1", s, 2));
				}
				else if (s[len] == '.')
					len--;
				else
					s[len--] = '0';
			}
		s[len] += 1;
	}
	s[i] = '\0';
	return (s);
}
