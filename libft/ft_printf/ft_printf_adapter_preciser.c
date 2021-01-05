/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adapter_preciser.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:10:41 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	prec_s(t_ph *p, int len)
{
	if (p->pres > 0 && p->wpdif > 0 && len > 0 && (p->pres + p->wpdif < len))
		p->out = ft_strndup_free(p->out, p->pres + p->wpdif, 1);
	if (p->pres > 0 && p->wpdif <= 0 && len > 0 && (p->pres < len))
		p->out = ft_strndup_free(p->out, p->pres, 1);
	if (p->null == 1 && p->pres <= 5 && len > 0)
		ft_strclr(p->out);
	else if (len > 0 && p->pres < len)
		ft_strclr(p->out + p->pres);
}

void	prec_diouxxp(t_ph *p, int len)
{
	if (p->pres == 0 && p->sign == '0' && !(p->type == 'o' && p->tag == 1))
		ft_strclr(p->out);
	if ((p->pres > len) || ((p->type == 'd' || p->type == 'i') \
		&& p->sign == '-' && p->pres >= len))
	{
		while ((len < p->pres) || ((p->type == 'd' || p->type == 'i') \
			&& p->sign == '-' && p->pres >= len))
		{
			p->out = ft_strjoin_free("0", p->out, 2);
			p->zos = 1;
			len++;
		}
		if ((p->type == 'd' || p->type == 'i') \
			&& p->sign == '-' && p->pres < len)
			p->out[0] = '-';
		else if (p->sign == '-')
			p->out = ft_strjoin_free("-", p->out, 2);
	}
}

int		ft_preciser(t_ph *p, int len)
{
	if (p->type == 'p' || p->type == 'd' || p->type == 'i' \
		|| p->type == 'o' || p->type == 'u' || p->type == 'x' \
		|| p->type == 'X')
		prec_diouxxp(p, len);
	if (p->type == 's')
		prec_s(p, len);
	return (ft_strlen(p->out));
}
