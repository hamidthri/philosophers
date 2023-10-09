/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:59:00 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:46:24 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	newline;

	i = 0;
	newline = '\n';
	while (*(s + i) != '\0')
	{
		write (fd, &*(s + i), sizeof(char));
		i++;
	}
	write (fd, &newline, 1);
}
