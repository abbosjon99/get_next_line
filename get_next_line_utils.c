/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:33 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/01 19:20:53 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

fj	ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	fj	dataset;

	j = 0;
	if (s1)
		j = ft_strlen(s1);
	dataset.i = ft_strnlen(s2);
	dataset.nxtline = (char *)malloc(j + dataset.i + 2);
	if (!dataset.nxtline)
		return (dataset);
	i = 0;
	while (s1 && s1[i] && ++i)
		dataset.nxtline[i - 1] = s1[i - 1];
	j = 0;
	while (j < dataset.i + 1)
	{
		dataset.nxtline[i + j] = s2[j];
		j++;
	}
	dataset.nxtline[i + j] = '\0';
	if (s2[j] == '\0')
		dataset.i = 0;
	return (dataset);
}

size_t	ft_strnlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\n' && s[size] != '\0')
		size++;
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	i = 0;
	if (!src && !dest)
		return (NULL);
	ptr_dest = dest;
	ptr_src = src;
	if (src < dest)
	{
		while (n-- > 0)
		{
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}

// char	*ft_strndup(const char *s)
// {
// 	size_t	size;
// 	char	*newstr;

// 	size = ft_strnlen(s);
// 	newstr = (char *)malloc(sizeof(char) * (size + 1));
// 	if (!newstr)
// 		return (NULL);
// 	newstr[size] = s[size];
// 	while (size-- > 0)
// 	{
// 		newstr[size] = s[size];
// 	}
// 	return (newstr);
// }


// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] == s2[i] && s1[i] != '\0')
// 		i++;
// 	return (s1[i] - s2[i]);
// }
