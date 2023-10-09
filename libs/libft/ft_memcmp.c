/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:59:20 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:44:31 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	if (n == 0 || str1 == str2)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (n != 0)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
