/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:24:30 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/25 13:24:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_intarr_print(int **arr, int max_rows, int max_cols) //fd
{
	int i;
	int	j;

	i = -1;
	while(++i < max_rows)
	{
		j = -1;
		while(++j < max_cols)
			printf("%2i", arr[i][j]);
		printf("\n");
	}
}

int		**ft_inttab_malloc(int max_rows, int max_cols)
{
	int		**tmp;
	int		i;

	i = -1;
	if(!(tmp = (int **)malloc((max_rows) * sizeof(int *))))
		return (NULL);
	while (++i < max_rows)
	{
		if(!(tmp[i] = (int *)malloc((max_cols) * sizeof(int))))
			return (NULL);
	}
	return (tmp);
}
