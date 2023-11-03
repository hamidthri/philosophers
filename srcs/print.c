/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:58:03 by htaheri           #+#    #+#             */
/*   Updated: 2023/10/31 15:39:15 by iwillens         ###   ########.fr       */
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
	pthread_mutex_lock(&(philo->data->print));
	if (!(is_someone_dead(philo->data)) && !is_someone_finished(philo->data))
	{
		printf("%lld %d %s\n", current_time() - philo->data->t_start,
			philo->n, str);
	}
	pthread_mutex_unlock(&(philo->data->print));
}

void	pause_time(int t)
{
	long long	time;

	time = current_time();
	while (current_time() - time < t)
		usleep(t / 100);
}
