/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:22 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/01 05:30:14 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			i;
	const char	*temp;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// if (!temp)
	// {
	// 	nextline = ft_strdup((char *)temp);
	// 	if (ft_strcmp(temp, nextline) != 0)
	// 	{
	// 		while (*temp != '\n')
	// 			temp++;
	// 		return (nextline);
	// 	}
	// 	else
	// 	{
	// 		free(temp);
	// 		temp = NULL;
	// 		if (nextline[ft_strlen(nextline)] == '\n')
	// 			return (nextline);
	// 	}
	// }
	temp = (const char *)malloc(BUFFER_SIZE);
	while (read(fd, (void *)temp, BUFFER_SIZE))
	{
		nextline = ft_strdup(temp);
	}
	return (nextline);
}
