/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:57:57 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/04 16:44:31 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	int		len;
	int		ncpy;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	ncpy = n;
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
		n = -n;
	if (n == 0)
		str[0] = n + '0';
	while (len >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (ncpy < 0)
		str[0] = '-';
	return (str);
}
