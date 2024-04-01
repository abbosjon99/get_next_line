/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:27 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/01 19:40:34 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct forjoin
{
	char    *nxtline;
	size_t  i;
} fj;


char	*get_next_line(int fd);
fj	ft_strjoin(char const *s1, char const *s2);
// char	*ft_strndup(const char *s);
// int	ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif
