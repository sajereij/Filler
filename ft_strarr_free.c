/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:53:34 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/28 00:25:22 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_strarr_free(char **arr)
{
	int	rows;

	rows = ft_strarrsize(arr);
	while (rows > -1)
	{
		ft_strdel(&arr[rows]);
		rows--;
	}
	free(arr);
	arr = NULL;
}
