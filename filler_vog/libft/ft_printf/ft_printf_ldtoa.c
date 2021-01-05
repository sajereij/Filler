/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ldtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:20:29 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		str_parts(__int128_t nb, char *str, int d)
{
	int i;
	int j;

	j = d - ft_bigintlen(nb, 10) + 1;
	i = 0;
	if (nb == 0)
		str[i++] = '0';
	while (nb != 0)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	while (j-- > 0 && d > 0)
		str[i++] = '0';
	while (i < d)
		str[i++] = '0';
	ft_strrev(str, i);
	str[i] = '\0';
	return (i);
}

void	ftype_zeroer(t_ph *p, char **out)
{
	int i;
	int	len;
	int sign;
	int sp;

	sp = p->space;
	sign = (p->sign == '-' || p->plus == 1) ? 1 : 0;
	sp = (p->sign == '-' || p->plus == 1) ? 0 : p->space;
	len = ft_strlen(*out);
	i = -1;
	while (p->wid > len && (++i < (p->wid - (len + sp + sign))))
	{
		*out = ft_strjoin_free("0", *out, 2);
		p->zos = 1;
	}
}

char	*ft_printf_ldtoa(long double n, int afterpoint, t_ph *p)
{
	__int128_t	pre;
	__int128_t	dec;
	long double	post;
	char		*out;
	int			len;

	(n < 0) ? p->sign = '-' : 0;
	(n == 0) ? p->sign = '0' : 0;
	n = (n < 0) ? -n : n;
	pre = (__int128_t)n;
	out = ft_memalloc(sizeof(char) * (ft_bigintlen(pre, 10) + afterpoint + 3));
	post = n - (long double)pre;
	len = str_parts(pre, out, 0);
	if (afterpoint != 0)
		out[len++] = '.';
	dec = post * ft_pow(10, afterpoint + 1);
	len += str_parts(dec, out + len, afterpoint);
	out = ft_strround_up(out, len - 1, p->sign);
	if (p->tag == 1 && afterpoint == 0)
		out = ft_strjoin_free(out, ".", 1);
	(p->zero == 1 && p->minus == 0) ? ftype_zeroer(p, &out) : 0;
	(p->sign == '-') ? out = ft_strjoin_free("-", out, 2) : 0;
	return (out);
}
