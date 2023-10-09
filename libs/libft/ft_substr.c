/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:11:50 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:51:21 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_l;
	char		*dest;
	int			j;

	s_l = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_l >= start && s_l <= start + len)
		len = s_l - start;
	if (s_l < start)
		return (ft_calloc(1, sizeof(char)));
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	j = 0;
	while (len-- && s)
	{
		*(dest + j) = *(s + start + j);
		j++;
	}
	*(dest + j) = '\0';
	return (dest);
}
