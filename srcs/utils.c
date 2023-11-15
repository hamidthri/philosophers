/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:15:55 by htaheri           #+#    #+#             */
/*   Updated: 2023/11/05 18:02:58 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_digit(char *args)
{
	int	i;

	i = 0;
	if ((args[i] == '+') && ft_isdigit(args[i + 1]))
		i++;
	while (args[i])
	{
		while (args[i] == ' ' || args[i] == '\t')
			i++;
		if ((args[i] == '+') && !(args[i - 1]))
			i++;
		if (!ft_isdigit(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_integer(char **args)
{
	int		i;

	i = 2;
	while (args[i])
	{
		if (!is_digit(args[i]))
			return (0);
		i++;
	}
	return (1);
}

long	long_atoi(char *str)
{
	int			i;
	int			flag;
	long		num;

	i = 0;
	flag = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (flag * num);
}

void	*exit_code(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->n_phil)
		pthread_mutex_unlock(data->philo[i++].fork_right);
	return (NULL);
}
