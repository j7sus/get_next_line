/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:34:17 by jecontre          #+#    #+#             */
/*   Updated: 2023/02/09 16:50:21 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = mallloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	line[i] = '\0';
	return (line);
}
