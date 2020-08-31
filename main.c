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

int		main(void)
{
	t_d		data;
	int		ret;

	init_struct(&data);
	data.fd = open("q", O_WRONLY | O_CREAT);
	set_player(&data);
	while (1)
	{
		get_data(&data);
		if ((ret = choose_move(&data)) < 0)
		{	
			if (ret == -1)
				write(2, "No more moves left!\n", 20);
			if (ret == -2)
				write(2, "Piece bigger than map!\n", 20);
			
			break;
			
			//return (0);
		}
	}
	return (0);
}
