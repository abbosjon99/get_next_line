/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:22 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/22 15:38:25 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_get_line(int fd, char **readed, int firstrun)
{
	int	i;

	if (firstrun == 1)
	{
		if (*readed && firstrun == 1)
			return (ft_strnlen(*readed));
		*readed = malloc((long int)BUFFER_SIZE + 1);
		if (!(*readed))
		{
			*readed = NULL;
			return (0);
		}
	}
	i = read(fd, *readed, BUFFER_SIZE);
	if (i >= 0)
	{
		(*readed)[i] = '\0';
		i = ft_strnlen(*readed);
	}
	else
	{
		free(*readed);
		(*readed) = NULL;
	}
	return (i);
}

char	*ft_free_error(char **s1, char *s2)
{
	if ((*s1))
		free((*s1));
	(*s1) = NULL;
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*saved[2048];
	int			i;
	char		*result;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = ft_get_line(fd, &saved[fd], 1);
	while (i > 0)
	{
		result = ft_strjoin(&result, saved[fd], i);
		if (!result)
			return (ft_free_error(&saved[fd], NULL));
		if (saved[fd][i - 1] == 10)
		{
			if (saved[fd][i] == 0)
				break ;
			saved[fd] = ft_charshifter(saved[fd], i);
			return (result);
		}
		i = ft_get_line(fd, &saved[fd], 0);
	}
	return (ft_free_error(&saved[fd], result));
}
