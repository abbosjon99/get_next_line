/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:22 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/02 01:19:07 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			i;
	static char	*saved;
	char		*temp;
	t_fj		dset;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	dset.nxtline = NULL;
	if (saved && *saved)
	{
		dset = ft_strjoin(dset.nxtline, saved);
		if (dset.i != 0)
		{
			temp = ft_strdup(saved + dset.i);
			free(saved);
			saved = ft_strdup(temp);
			free(temp);
			return (dset.nxtline);
		}
		free(saved);
	}
	else
		saved = malloc(BUFFER_SIZE + 1);
	temp = malloc(BUFFER_SIZE);
	if (!temp)
		return (NULL);
	i = read(fd, temp, BUFFER_SIZE);
	if (i <= 0)
		return (NULL);
	while (i > 0)
	{
		dset = ft_strjoin(dset.nxtline, temp);
		if (dset.i != 0)
		{
			saved = ft_strdup(temp + dset.i);
			free(temp);
			return (dset.nxtline);
		}
		i = read(fd, temp, BUFFER_SIZE);
	}
	free(saved);
	return (dset.nxtline);
}
