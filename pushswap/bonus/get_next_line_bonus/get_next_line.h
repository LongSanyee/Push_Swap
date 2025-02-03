/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:17 by rammisse          #+#    #+#             */
/*   Updated: 2025/02/03 14:46:18 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

#endif