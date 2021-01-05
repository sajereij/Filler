/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:24:02 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:49:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

__int128_t		ft_pow(__int128 base, long long pow)
{
	if (pow == 0)
		return (1);
	else if (pow % 2 == 0)
		return (ft_pow(base, pow / 2) * ft_pow(base, pow / 2));
	else
		return (base * ft_pow(base, pow / 2) * ft_pow(base, pow / 2));
}
