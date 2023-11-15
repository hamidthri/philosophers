/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:51:59 by htaheri           #+#    #+#             */
/*   Updated: 2023/11/05 13:59:46 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	test_(t_philo *philo)
{
	if (!philo->data->n_eat)
		return (0);
	pthread_mutex_lock(&(philo->eating_mtx));
	if (philo->eat_counter == philo->data->n_eat)
	{
		pthread_mutex_unlock(&(philo->eating_mtx));
		return (1);
	}
	pthread_mutex_unlock(&(philo->eating_mtx));
	return (0);
}

void	eating(t_philo *philo)
{
	if (!test_(philo))
	{
		print(philo, " is eating");
		philo->eat_counter++;
		pthread_mutex_lock(&(philo->eating_mtx));
		philo->last_eat = current_time();
		pthread_mutex_unlock(&(philo->eating_mtx));
		pause_time(philo->data->t_eat);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
}

void	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print(philo, " has taken a fork");
	pthread_mutex_lock(philo->fork_left);
	print(philo, " has taken a fork");
}

void	*routin(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if ((philo->n + 1) % 2)
		pause_time(philo->data->t_eat / 10);
	while (!eat_enough(philo->data) && !is_someone_finished(philo->data)
		&& !is_someone_dead(philo->data))
	{
		taking_fork(philo);
		eating(philo);
		if (!eat_enough(philo->data) && !is_someone_finished(philo->data))
		{
			print(philo, " is sleeping");
			pause_time(philo->data->t_sleep);
		}
		if (!eat_enough(philo->data) && !is_someone_finished(philo->data))
			print(philo, " is thinking");
	}
	return (NULL);
}
