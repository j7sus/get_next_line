/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecontre <jecontre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:52:55 by jecontre          #+#    #+#             */
/*   Updated: 2023/02/09 17:14:51 by jecontre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next(char *str)
{
	int		len1;
	int		len2;
	char	*next;

	while (str[len1] != '\n')
		len1++;
	if (str[len1] == '\n')
		len1++;
	len2 = len1;
	while (str[len2] != '\n')
		len2++;
	while (str[len2] == '\n')
		len2++;
	next = malloc(len2 * sizeof(char));
	if (!next)
		return (NULL);
	len2 = 0;
	while (str[len1] != '\n')
	{
		next[len2] = str[len1];
		len1++;
		len2++;
	}
	return (next);
}
