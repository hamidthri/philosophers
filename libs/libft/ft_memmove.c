/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:04:17 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:45:05 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!s && !d && n)
		return (NULL);
	if (s > d)
		while (n--)
			*d++ = *s++;
	else
	{
		while (n > 0)
		{
			*(d + n - 1) = *(s + n - 1);
			n--;
		}
	}
	return (dst);
}
