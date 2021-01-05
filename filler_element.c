/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:58:34 by sreijola          #+#    #+#             */
/*   Updated: 2020/10/01 16:29:12 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_content(char *line, int max_cols, int cut)
{
	int i;

	i = cut;
	while (line[i] != '\0')
	{
		if (line[i] != '*' && line[i] != '.'\
		&& line[i] != 'X' && line[i] != 'x'\
		&& line[i] != 'O' && line[i] != 'o')
			return (0);
		i++;
	}
	if (i - cut != max_cols)
		return (0);
	return (1);
}

int		trim_map(char *line)
{
	int	trim;

	trim = 0;
	while ((ft_isdigit(line[trim]) || line[trim] == ' ') && line[trim])
		trim++;
	return (trim);
}

char	**get_element(int rows, int cols, char *line, int element)
{
	int		i;
	int		cut;
	char	**tmp;

	i = -1;
	cut = 0;
	if (!(tmp = ft_strarr_malloc(rows, cols)))
		return (NULL);
	while (++i < rows)
	{
		ft_strclr(line);
		get_next_line(0, &line);
		cut = (element == 'm') ? trim_map(line) : 0;
		if (check_content(line, cols, cut))
		{
			line += (element == 'm') ? cut : 0;
			ft_strcpy(tmp[i], line);
		}
		else
			return (NULL);
	}
	tmp[i] = NULL;
	if (ft_strarrsize(tmp) != rows) //eroavaisuus
		return (NULL);
	return (tmp);
}
