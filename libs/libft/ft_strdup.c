/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:49:18 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:48:00 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dest;
	size_t		src_l;
	int			i;

	i = 0;
	src_l = ft_strlen(s);
	dest = malloc((src_l + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src_l)
	{
		*(dest + i) = *(s + i);
		i++;
		src_l--;
	}
	*(dest + i) = '\0';
	return (dest);
}
