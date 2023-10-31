/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:18:30 by htaheri           #+#    #+#             */
/*   Updated: 2023/10/31 15:36:33 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_someone_dead(t_data *data)
{
	pthread_mutex_lock(&(data->dead));
	if (data->someone_died)
	{
		pthread_mutex_unlock(&(data->dead));
		return (1);
	}
	pthread_mutex_unlock(&(data->dead));
	return (0);
}

int	is_someone_finished(t_data *data)
{
	pthread_mutex_lock(&(data->finished));
	if (data->someone_finished)
	{
		pthread_mutex_unlock(&(data->finished));
		return (1);
	}
	pthread_mutex_unlock(&(data->finished));
	return (0);
}

void	set_someone_finished(t_data *data)
{
	pthread_mutex_lock(&(data->finished));
	data->someone_finished = 1;
	pthread_mutex_unlock(&(data->finished));
}

int	test(t_philo *philo)
{
	int		count;

	count = 0;
	if (!philo->data->n_eat)
		return (0);
	pthread_mutex_lock(&(philo->eating_mtx));
	if (philo->eat_counter == philo->data->n_eat)
	{
		return (1);
		pthread_mutex_unlock(&(philo->eating_mtx));
	}
	pthread_mutex_unlock(&(philo->eating_mtx));
	return (0);
}

int	eat_enough(t_data *data)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!data->n_eat)
		return (0);
	while (i < data->n_phil)
	{
		pthread_mutex_lock(&(data->philo[i].eating_mtx));
		if (data->n_eat <= data->philo[i].eat_counter)
			count++;
		pthread_mutex_unlock(&(data->philo[i].eating_mtx));
		i++;
	}
	if (i <= count)
		return (1);
	return (0);
}

void	*check_status(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	while (!is_someone_finished(data) && !is_someone_dead(data))
	{
		i = 0;
		while (i < data->n_phil)
		{
			pthread_mutex_lock(&(data->philo[i].eating_mtx));
			if (current_time() - data->philo[i].last_eat > data->t_die)
			{
				pthread_mutex_lock(&(data->mtx_someone_died));
				print(data->philo, " died");
				data->someone_died = 1;
				pthread_mutex_unlock(&(data->mtx_someone_died));
				pthread_mutex_unlock(&(data->philo[i].eating_mtx));
				break ;
			}
			else
				pthread_mutex_unlock(&(data->philo[i].eating_mtx));


			/*code for checking finished*/
			if (eat_enough(data))
				set_someone_finished(data);




			i++;
		}
	}
	i = 0;
	while (i < data->n_phil)
		pthread_mutex_unlock(data->philo[i++].fork_right);
	return (NULL);
}
