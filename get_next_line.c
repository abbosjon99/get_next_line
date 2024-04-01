/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:22 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/01 19:43:53 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			i;
	static char	*temp;
	fj	dset;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	dset.nxtline = NULL;
	if (temp)
	{
		dset = ft_strjoin(dset.nxtline, temp);
		if (dset.i != 0)
		{
			ft_memmove(temp, (temp + dset.i + 1), ft_strlen(temp + dset.i));
			return (dset.nxtline);
		}
	}
	else
		temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	i = read(fd, temp, BUFFER_SIZE);
	while (i)
	{
		printf("\n\trun\n");
		dset = ft_strjoin(dset.nxtline, temp);
		if (dset.i != 0)
		{
			ft_memmove(temp, (temp + dset.i + 1), ft_strlen(temp + dset.i));
			return (dset.nxtline);
		}
		i = read(fd, temp, BUFFER_SIZE);
	}
	return (dset.nxtline);
}
