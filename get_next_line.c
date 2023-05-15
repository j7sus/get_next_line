/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:52:55 by jecontre          #+#    #+#             */
/*   Updated: 2023/05/15 11:00:30 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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
<<<<<<< HEAD
	int		bytes;
=======
	int	bytes;
>>>>>>> 543dd755649af709a4a5e29fabe27d50ee63c2cd

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
<<<<<<< HEAD
	char		*line;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = reader(fd, buff);
	if (!buff)
=======
	char	*line;
	static char	*buff;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = char	*reader(fd, buff);
	If (!buff)
>>>>>>> 543dd755649af709a4a5e29fabe27d50ee63c2cd
		return (NULL);
	line = ft_line(buff);
	buff = ft_next(buff);
	return (line);
}

<<<<<<< HEAD
int	main(void)
{
	int	fd = open("get_next_line/text.txt", O_RDONLY);
	char	*line;
	int	i;

	i = 0;
	//line = NULL;
	if (i < 20)
	{
		line = get_next_line(fd);
		printf("line: %d texto:  %s", i, line);
		return (0);
		free (line);
		i++;
	}
	close (fd);
}

/*
int	main(void)
=======
int	main()
>>>>>>> 543dd755649af709a4a5e29fabe27d50ee63c2cd
{
	char	*line;
	char	*next;
	char	*str;

	str = "Hola mundo todo bien?\nhola destino\n Si todo bien\n";
	line = ft_line(str);
	next = ft_next(str);
	printf("%s", line);
	printf("%s", next);
	free(line);
	free(next);
	return (0);
}*/
