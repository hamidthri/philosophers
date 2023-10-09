/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:09:01 by htaheri           #+#    #+#             */
/*   Updated: 2023/04/09 21:39:26 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_digit(int n)
{
	int		len;

	len = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*final_num(char *num, int n, int len, int flag)
{
	while (n / 10)
	{
		num [len + flag - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	num [len + flag - 1] = n + '0';
	return (num);
}

char	*ft_itoa(int n)
{
	int		flag;
	int		len;
	char	*num;

	flag = 0;
	len = len_digit(n);
	if (n < 0)
		flag = 1;
	num = (char *)malloc((len + flag + 1) * sizeof(char));
	if (!num)
		return (NULL);
	if (n == -2147483648)
	{
		num[1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		n = -n;
		num[0] = '-';
	}
	num = final_num(num, n, len, flag);
	num[len + flag] = '\0';
	return (num);
}
