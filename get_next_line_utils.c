/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:33 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/02 01:12:10 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fj	ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	t_fj	dataset;

	j = 0;
	if (s1)
		j = ft_strlen(s1);
	dataset.i = ft_strnlen(s2) + 1;
	dataset.nxtline = (char *)malloc(j + dataset.i);
	if (!dataset.nxtline)
		return (dataset);
	i = 0;
	while (s1 && s1[i] && ++i)
		dataset.nxtline[i - 1] = s1[i - 1];
	j = 0;
	while (j < dataset.i)
	{
		dataset.nxtline[i + j] = s2[j];
		j++;
	}
	if (s2[j - 1] != '\n')
		dataset.i = 0;
	return (dataset);
}

size_t	ft_strnlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\n' && s[size] != '\0')
	{
		if (s[size] == '\n')
			return (size + 1);
		size++;
	}
	return (size);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*newstr;

	i = 0;
	size = ft_strlen(s);
	newstr = malloc(size + 1);
	if (!newstr)
		return (NULL);
	while (i < size)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
