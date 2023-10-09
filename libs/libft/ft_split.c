/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:19:31 by htaheri           #+#    #+#             */
/*   Updated: 2023/07/25 14:48:27 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	memory_free(int k, char **strings)
{
	while (k >= 0)
	{
		free(strings[k]);
		k--;
	}
	free(strings);
	return (0);
}

int	word_count(char const *s, char c)
{
	int		counter;

	counter = 0;
	if (!s || *s == '\0')
		return (0);
	else if (c == '\0')
		return (1);
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
				s++;
			counter++;
		}
		if (*s != '\0')
			s++;
	}
	return (counter);
}

static void	word_write(char	*array, char const *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
}

int	find_str(char	**array, char const *s, char c)
{
	size_t		i;
	size_t		len_word;
	size_t		word_count;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len_word = 0;
			while (s[i + len_word] != c && s[i + len_word])
				len_word++;
			array[word_count] = (char *)ft_calloc((len_word + 1), sizeof(char));
			if (array[word_count] == NULL)
				return (memory_free(word_count, array));
			word_write(array[word_count], s + i, c);
			i += len_word;
			word_count++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t		count;
	char		**array;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	array = (char **)ft_calloc((count + 1), sizeof(array));
	if (array == NULL)
		return (NULL);
	if (find_str(array, s, c) == 0)
		return (NULL);
	array[count] = NULL;
	return (array);
}
