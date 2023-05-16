/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:52:55 by jecontre          #+#    #+#             */
/*   Updated: 2023/05/16 13:07:05 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_line(char *str, char *line)
{
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_next(char *str)
{
	int		len1;
	int		len2;
	char	*next;

	len1 = 0;
	while (str[len1] && str[len1] != '\n')
		len1++;
	if (!str)
		return (ft_free(&str, NULL));
	next = ft_calloc(ft_strlen(str) - len1 + 1, sizeof(char));
	if (!next)
		return (ft_free(&str, NULL));
	len1++;
	len2 = 0;
	while (str[len1])
	{
		next[len2] = str[len1];
		len1++;
		len2++;
	}
	ft_free(&str, NULL);
	return (next);
}

char	*ft_free_join(char *buff, char *read)
{	
	char	*tmp;	

	tmp = ft_strjoin(buff, read);
	if (!tmp)
		return (ft_free(&buff, &read));
	ft_free(&buff, 0);
	return (tmp);
}

char	*reader(int fd, char *buff, int bytes)
{
	char	*tmp;

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
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			bytes;
	static char	*buff = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buff)
			ft_free(&buff, NULL);
		return (NULL);
	}
	if (!buff)
		buff = ft_calloc(1, 1);
	if (!buff)
		return (ft_free(&buff, NULL));
	bytes = 1;
	buff = reader(fd, buff, bytes);
	if (!buff)
		return (NULL);
	line = ft_line(buff, line);
	if (!line || *line == '\0')
		return (ft_free(&buff, &line));
	buff = ft_next(buff);
	return (line);
}
/*
int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char	*line;
	//char *str= "hola\nmundo";
	int i = 0;
	int j = 0;

	line = NULL;
	if (fd < 0)
	{
		printf("Error!!-->memory allocation\n");
		return (0);
	}
	while (j==0)
	{	
		line = get_next_line(fd);
		if (!line)
			break;
		printf("line [%d] content :%s\n\n", i++, line);
	}
	//line = ft_next(str);
	
	
	
	close (fd);
	return (0);
}*/
