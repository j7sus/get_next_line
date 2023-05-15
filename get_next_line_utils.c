/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:31:08 by jecontre          #+#    #+#             */
/*   Updated: 2023/05/15 16:33:23 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	size_t	tmp;
	void	*memory;

	tmp = count * size;
	memory = malloc(tmp);
	if (!memory)
		return (NULL);
	len = 0;
	while (len < tmp)
	{
		((char*)memory)[len] = 0;
		len++;
	}
	return (memory);
}

char	*ft_free(char **buff1, char **buff2)
{
	if (buff1 && *buff1)
	{
		free(*buff1);
		*buff1 = NULL;
	}
	if (buff2 && *buff2)
	{
		free(*buff2);
		*buff2 = NULL;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i++] == (char)c)
			return ((char *)&s[i]); 
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!dst)
		return (NULL);
	while (str1[i])
		dst[j++] = str1[i++];
	i = 0;
	while (str2[i])
		dst[j++] = str2[i++];
	dst[j] = '\0';
	return (dst);
}