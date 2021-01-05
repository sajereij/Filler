/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:50:01 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/27 19:20:43 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
