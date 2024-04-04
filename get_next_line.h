/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:27 by akeldiya          #+#    #+#             */
/*   Updated: 2024/04/02 01:11:00 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct t_forjoin
{
	char	*nxtline;
	size_t	i;
}			t_fj;

char		*get_next_line(int fd);
t_fj		ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s);
char		*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
