/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabarr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 04:22:07 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/07 13:21:50 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_tabarr_print(int **arr, int maxr, int maxc)
{
	int		i;
	int		j;

	i = -1;
	while (++i < maxr)
	{
		j = 0;
		while (j < maxc)
		{
			ft_printf("%2i", arr[i][j]);
			j++;
		}
		ft_printf("\n");
	}
}
