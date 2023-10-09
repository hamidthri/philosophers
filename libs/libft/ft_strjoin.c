/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:32:22 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:48:50 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*cat;
	char		*cat_m;
	int			s1_l;
	int			s2_l;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	cat = (char *) malloc((s1_l + s2_l + 1) * sizeof(char));
	if (!cat)
		return (0);
	cat_m = cat;
	while (*s1)
		*cat++ = *s1++;
	while (*s2)
		*cat++ = *s2++;
	*cat = '\0';
	return (cat_m);
}
