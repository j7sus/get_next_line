/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:31:08 by jecontre          #+#    #+#             */
/*   Updated: 2023/02/20 11:54:26 by jecontre         ###   ########.fr       */
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

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	dst = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (str1[i] != '\0')
	{
		dst[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		dst[i] = str2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_bzero(char *str, size_t n)
{
	size_t	i;
	char	*str_clean;

	str_clean = str;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	size_t	*tmp;
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