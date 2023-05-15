/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:31:08 by jecontre          #+#    #+#             */
/*   Updated: 2023/05/15 11:58:14 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *str1, char const *str2)
// {
// 	char	*dst;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	dst = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
// 	if (!dst)
// 		return (NULL);
// 	while (str1[i] != '\0')
// 	{
// 		dst[i] = str1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (str2[j] != '\0')
// 	{
// 		dst[i] = str2[j];
// 		i++;
// 		j++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	len;
// 	size_t	tmp;
// 	void	*memory;

// 	tmp = count * size;
// 	memory = malloc(tmp);
// 	if (!memory)
// 		return (NULL);
// 	len = 0;
// 	while (len < tmp)
// 	{
// 		((char*)memory)[len] = 0;
// 		len++;
// 	}
// 	return (memory);
// }

// char	*ft_free(char **buff1, char **buff2)
// {
// 	if (*buff1 && buff1)
// 	{
// 		free(*buff1);
// 		*buff1 = NULL;
// 	}
// 	if (*buff2 && buff2)
// 	{
// 		free(*buff2);
// 		*buff2 = NULL;
// 	}
// 	return (NULL);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i++] == (char)c)
// 			return ((char *)&s[i]); 
// 	}
// 	if ((char)c == '\0' && s[i] == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	asign;
	size_t	i;

	asign = count * size;
	memory = malloc(asign);
	if (!memory)
		return (0);
	i = 0;
	while (i < asign)
		((char *)memory)[i++] = 0;
	return (memory);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_free(char **buff, char **buff2)
{
	if (buff && *buff)
	{
		free(*buff);
		*buff = NULL;
	}
	if (buff2 && *buff2)
	{
		free(*buff2);
		*buff2 = NULL;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*n_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!n_str)
		return (NULL);
	while (s1[i])
		n_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		n_str[j++] = s2[i++];
	n_str[j] = '\0';
	return (n_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}