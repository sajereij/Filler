/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:50:01 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/25 12:50:01 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_strarr_free(char **arr, int rows)
{
	while (rows > -1)
	{
		free(arr[rows]);
		rows--;
	}
	free(arr);
//	ft_strarr_print(arr);
}

// char	**ft_strarr_trim(char **arr, int first_row, int first_col, int last_row, int last_col, int max_rows)
// {
// 	int		i;
// 	int		max_cols;
// 	char	**tmp;

// 	i = -1;
// 	if(!(tmp = (char **)malloc(((last_row - first_row + 2) * sizeof(char *)))))
// 		return (NULL);
// 	while (++i + first_row <= last_row)
// 		tmp[i] = ft_strsub(d->pc[first_row + i], first_col, last_col - first_col + 1);	
// 	tmp[i] = NULL;
// 	ft_strarr_free(arr, max_rows);
// 	max_rows -= (first_row) + (max_rows - last_row - 1);
// 	max_cols = ft_strlen(tmp[0]);
// 	printf("new dim: y %d x %d\n", max_rows, max_cols);
// 	return (tmp);
// }

void	ft_strarr_print_fd(char **arr, int fd) //fd
{
	int i;
	
	i = -1;
	while (arr[++i] != NULL)
	{
		ft_putstr_fd(arr[i], fd);
		ft_putchar_fd('\n', fd);
	}
	ft_putchar_fd('\n', fd);
}

void	ft_strarr_print(char **arr) //fd
{
	int i;
	
	i = -1;
	while (arr[++i] != NULL)
		printf("%s\n", arr[i]);
	printf("\n");
	
}

char	**ft_strarr_malloc(int rows, int cols)
{
	int		i;
	char	**tmp;

	i = -1;
	if(!(tmp = (char **)malloc((rows + 1) * sizeof(char *))))
		return (NULL);
	while (++i < rows)
	{
		if(!(tmp[i] = (char *)malloc((cols + 1) * sizeof(char))))
			return (NULL);
	}
	tmp[i] = NULL;
//	ftt_strarr_prin(tmp);
	return (tmp);
}
