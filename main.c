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

#include <stdio.h>
#include "filler.h"

int		main()
{
	char	*line;
	
	printf("halojaa\n");
	get_next_line(1, &line);
	printf("halojaa\n");
	printf("#####%s######\n", line);
	//get_data();
	return (0);
}
