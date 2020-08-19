/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:51:21 by sreijola          #+#    #+#             */
/*   Updated: 2020/08/19 17:53:28 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define FD_MAX 4864
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
