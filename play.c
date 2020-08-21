/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 21:38:36 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/20 21:38:36 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_arr_fr(char **arr, int rows)
{
	while (rows >= 0)
	{
		free(arr[rows]);
		rows--;
	}
	free(arr);
}



void	play_pc(t_d *d)
{

//	printf("%d %d\n", nxy, nxx);
	ft_arr_fr(d->map, d->my);
	ft_arr_fr(d->pc, d->py);
}
