/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:55:23 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/27 18:55:40 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**ft_strarr_malloc(int rows, int cols)
{
	int		i;
	char	**tmp;

	i = -1;
	if (!(tmp = (char **)malloc((rows + 1) * sizeof(char *))))
		return (NULL);
	while (++i < rows)
	{
		if (!(tmp[i] = (char *)malloc((cols + 1) * sizeof(char))))
			return (NULL);
	}
	tmp[i] = NULL;
	return (tmp);
}
