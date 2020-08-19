/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:44:28 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/07 14:10:41 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(char const *s, char c)
{
	size_t wc;

	wc = 0;
	if (s)
	{
		while (*s)
		{
			while (*s == c && *s != '\0')
				s++;
			if (*s != c && *s != '\0')
				wc++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (wc);
}
