/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:35:58 by sreijola          #+#    #+#             */
/*   Updated: 2019/11/07 12:51:25 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fr;
	t_list	*cfr;

	if (!lst)
		return (NULL);
	if (!(fr = f(lst)))
		return (NULL);
	cfr = fr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(fr->next = f(lst)))
		{
			free(fr->next);
			return (NULL);
		}
		fr = fr->next;
	}
	return (cfr);
}
