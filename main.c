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

	init_struct(&data);
	get_data(&data);
	play_pc(&data);
	data.pnb == 1 ?	printf("%d %d\n", data.lmoy, data.lmox) : printf("%d %d\n", data.lmxy, data.lmxx);
	return (0);
}
