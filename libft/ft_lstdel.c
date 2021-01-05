/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:37:51 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/26 01:49:53 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	while (*alst)
	{
		ptr = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = ptr;
	}
	*alst = NULL;
}
