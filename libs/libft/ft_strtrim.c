/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:18:13 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:51:07 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trim_check(char c, char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *string, char const *set)
{
	int		str_l;
	int		j;
	int		i;
	char	*trimmed;

	j = 0;
	str_l = ft_strlen(string);
	if (!string)
		return (0);
	while (string[j] && trim_check(string[j], (char *) set))
		j++;
	while (str_l > j && trim_check(string[str_l - 1], (char *) set))
		str_l--;
	trimmed = malloc((str_l - j + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (str_l > j)
		trimmed[i++] = string[j++];
	trimmed[i] = '\0';
	return (trimmed);
}
