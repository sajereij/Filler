/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:51:05 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/03 11:30:06 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*fr;

	if (!(fr = (char *)malloc((size + 1) * sizeof(char))))
		return (0);
	while (size > 0)
	{
		fr[size] = '\0';
		size--;
	}
	fr[0] = '\0';
	return (fr);
}
