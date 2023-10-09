/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:24:13 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:49:16 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_l;

	src_l = ft_strlen(src);
	while (n--)
	{
		if (!*src || n == 0)
		{
			*dest = '\0';
			break ;
		}
		*dest = *src;
		dest ++;
		src ++;
	}
	return (src_l);
}
