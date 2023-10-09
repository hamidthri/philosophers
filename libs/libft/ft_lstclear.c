/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:27:13 by htaheri           #+#    #+#             */
/*   Updated: 2023/07/20 16:34:10 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list		*forward;

	while (!*lst)
		return ;
	while (*lst)
	{
		forward = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = forward;
	}
	*lst = NULL;
}
