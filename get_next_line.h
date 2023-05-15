/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:50:33 by jecontre          #+#    #+#             */
/*   Updated: 2023/05/15 11:53:06 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t  ft_strlen(const char *str);
char    *ft_strjoin(char *str1, char *str2);
void    *ft_calloc(size_t count, size_t size);
char    *ft_free(char **buff1, char **buff2);
char    *ft_strchr(const char *s, int c);

char    *ft_line(char *str);
char    *ft_next(char *str);

#endif
