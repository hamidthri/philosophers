/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:24 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:49:05 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	src_l;
	size_t	dest_l;
	size_t	i;

	src_l = ft_strlen(src);
	dest_l = ft_strlen(dest);
	i = 0;
	if (n == 0)
		return (src_l);
	while (n > dest_l + i + 1 && *(src + i) != '\0')
	{
		*(dest + dest_l + i) = *(src + i);
		i++;
	}
	*(dest + dest_l + i) = '\0';
	if (n < dest_l)
		return (src_l + n);
	return (src_l + dest_l);
}
