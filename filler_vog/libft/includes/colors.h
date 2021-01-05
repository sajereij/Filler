/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:21:29 by sreijola          #+#    #+#             */
/*   Updated: 2020/09/18 14:08:38 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

const char	*g_code[] = {
	"\x1b[30m",
	"\x1B[31m",
	"\x1B[32m",
	"\x1B[33m",
	"\x1B[34m",
	"\x1B[35m",
	"\x1B[36m",
	"\x1B[37m",
	"\x1b[38m",
	"\x1b[1;33m",
	"\x1B[0m"};

const char	*g_color[] = {
	"BLK",
	"RED",
	"GRN",
	"YEL",
	"BLU",
	"MAG",
	"CYA",
	"WHT",
	"PNK",
	"BLD",
	"RES"};
#endif
