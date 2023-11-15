/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:58:03 by htaheri           #+#    #+#             */
/*   Updated: 2023/11/03 15:21:16 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	current_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->data->dead));
	if (!philo->data->someone_died && !eat_enough(philo->data))
	{
		pthread_mutex_lock(&(philo->data->print));
		printf("%lld %d %s\n", current_time() - philo->data->t_start,
			philo->n, str);
		pthread_mutex_unlock(&(philo->data->print));
	}
	pthread_mutex_unlock(&(philo->data->dead));
}

void	pause_time(int t)
{
	long int	time;

	time = current_time();
	while (current_time() - time < t)
		usleep(t / 10);
}
