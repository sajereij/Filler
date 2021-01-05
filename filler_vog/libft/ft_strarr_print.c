/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:57:05 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/12 23:58:42 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_strarr_print(char **arr)
{
	int i;

	i = -1;
	while (arr[++i] != NULL)
	{
		ft_putstr(arr[i]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
