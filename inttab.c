/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inttab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:24:30 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/28 00:26:17 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_intarr_print_fd(int **arr, int max_rows, int max_cols, int fd)
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

void	ft_intarr_print(int **arr, int maxr, int maxc)
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

void	ft_intarr_free(int **tab, int max_rows)
{
	int		i;

	if (!tab)
		return ;
	i = max_rows + 1;
	while (--i >= 0)
		free(tab[i]);
	free(tab);
}

int		**ft_intarr_malloc(int max_rows, int max_cols)
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
