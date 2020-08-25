/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:05:24 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/18 12:05:24 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	t_d		data;
//	char	*line;

	init_struct(&data);
	set_player(&data);
	//while (1)
	// {
	get_data(&data);
	get_data(&data);
	choose_move(&data);
	// }
	return (0);
}
