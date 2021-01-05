/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:51:05 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 02:13:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*fr;

	if (!(fr = ft_memalloc((size + 1) * sizeof(char))))
		return (0);
	while (size > 0)
	{
		fr[size] = '\0';
		size--;
	}
	fr[0] = '\0';
	return (fr);
}
