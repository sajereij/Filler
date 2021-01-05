/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabarr_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 04:11:06 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/07 13:20:56 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		**ft_tabarr_malloc(int max_rows, int max_cols)
{
	int		**tmp;
	int		i;

	i = -1;
	if (!(tmp = (int **)malloc((max_rows) * sizeof(int *))))
		return (NULL);
	while (++i < max_rows)
	{
		if (!(tmp[i] = (int *)malloc((max_cols) * sizeof(int))))
			return (NULL);
	}
	return (tmp);
}
