/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:52:55 by jecontre          #+#    #+#             */
/*   Updated: 2023/05/15 12:52:03 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


char	*ft_line(char *str)
{
	char	*line;
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

char	*ft_free_join(char *buffer, char *reader)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, reader);
	if (!tmp)
		return (ft_free(&buffer, &reader));
	ft_free(&buffer, 0);
	return (tmp);
}

char	*reader(int fd, char *buff)
{
	char	*tmp;
	int		bytes = 1;

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
char	*ft_protec_join(char *buffer, char *reader)
{	
	char	*temp;

	temp = ft_strjoin(buffer, reader);
	if (!temp)
		return (ft_free(&buffer, &reader));
	ft_free(&buffer, 0);
	return (temp);
}
char	*ft_read_fd(int fd, char *buf, int bytes)
{
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (ft_free(&buf, &tmp));
	while (bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(&buf, &tmp));
		tmp[bytes] = '\0';
		buf = ft_protec_join(buf, tmp);
		if (!buf)
			return (NULL);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	ft_free(&tmp, NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			bytes;
	static char	*buff;

	line = NULL;
	buff = NULL;
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
	buff = reader(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_line(buff);
	if (!line || *line == '\0')
		return (ft_free(&buff, &line));
	buff = ft_next(buff);
	return (line);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char	*line;
	//char *str= "hola\nmundo";
	int i = 0;

	line = NULL;
	if (fd < 0)
	{
		printf("Error!!-->memory allocation\n");
		return (0);
	}
	line = get_next_line(fd);
	//line = ft_next(str);
	printf("line [%d] content :%s", i++, line);
	return (0);
}