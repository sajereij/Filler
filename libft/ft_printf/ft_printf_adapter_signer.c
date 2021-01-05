/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adapter_signer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:39:21 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:50:30 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_sign_pos_fixer(t_ph *p, int l)
{
	while (l > 0)
	{
		if (((p->out[l - 1] == '0' || p->out[l - 1] == '-')\
			&& p->out[l] == '-') || (p->out[l] == '+' && \
			(p->out[l - 1] == '0' || p->out[l - 1] == '+'))\
			|| (l > p->pres && p->out[l] == ' ' && p->minus == 0 \
			&& (p->out[l - 1] == '0' || (p->out[l - 1] == ' ' \
			&& p->space == 1 && p->zero == 1))))
		{
			p->out[l] = '0';
			return ;
		}
		l--;
	}
}
