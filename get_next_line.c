/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:52:55 by jecontre          #+#    #+#             */
/*   Updated: 2023/05/12 14:44:08 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *str)
{
	int		len1;
	int		len2;
	char	*next;

	len1 = 0;
	while (str[len1] != '\n' && str[len1])
		len1++;
	if (str[len1] == '\n')
		len1++;
	len2 = len1;
	while (str[len2] != '\n' && str[len2])
		len2++;
	if (str[len2] == '\n')
		len2++;
	next = malloc(len2 * sizeof(char));
	if (!next)
		return (NULL);
	len2 = 0;
	while (str[len1] != '\n' && str[len1])
	{
		next[len2] = str[len1];
		len1++;
		len2++;
	}
	next[len2] = '\0';
	return (next);
}

char *ft_free_join(char *buffer, char *reader)
{
	char *tmp;

	tmp = ft_strjoin(buffer, reader);
	if (!tmp)
		return (ft_free(&buffer, &reader));
	ft_free(&buffer, 0);
	return (tmp);
}

char	*reader(int fd, char *buff)
{
	char	*tmp;
	int	bytes;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (ft_free(&tmp, &buff));
	while (bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(&tmp, &buff));
		tmp[bytes] = '\0';
		buff = ft_free_join(buff, tmp);
		if (!buff)
			return (NULL);
		if (ft_strchr(tmp, '\n'))
				break ;
	}
	ft_free(&tmp, NULL);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*buff;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = char	*reader(fd, buff);
	If (!buff)
		return (NULL);
	line = ft_line(buff);
	buff = ft_next(buff);
	return (line);
}

int	main()
{
	char	*line;
	char	*next;
	char	*str;

	str = "Hola que tal?\n todo bien?\n llll";

	line = ft_line(str);
	next = ft_next(str);
	printf("%s", line);
	printf("%s", next);
	free(line);
	free(next);
	return (0);
}
