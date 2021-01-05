/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabarr_print_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 04:15:26 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/07 13:21:26 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_tabarr_print_fd(int **arr, int max_rows, int max_cols, int fd)
{
	int i;
	int	j;

	i = -1;
	while (++i < max_rows)
	{
		j = -1;
		while (++j < max_cols)
		{
			ft_putnbr_fd(arr[i][j], fd);
			ft_putchar_fd(' ', fd);
		}
		ft_putchar_fd('\n', fd);
	}
	ft_putchar_fd('\n', fd);
}
