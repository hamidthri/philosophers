/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:04:49 by htaheri           #+#    #+#             */
/*   Updated: 2023/10/17 19:28:20 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/philosophers.h"
#include <unistd.h>

void ft_putstr(char *s)
{
	{
		write(1, s, ft_strlen(s));
		s++;
	}
}

void eating(t_philo *philo)
{

	//	pthread_mutex_lock(philo[i].tid);
	//	usleep(philo->data->n_eat);
	//	pthread_mutex_unlock(data->philo[i].tid);
	(void)philo;
}

void *routin(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->n % 2)
		usleep(100);
	printf("Philosofer %d is born\n", philo->n);
	while (1)
	{
		printf("%d\n", philo->n);
		// eating(philo);
		return (NULL);
	}
	return (NULL);
}

void initialize_philo(t_data *data)
{
	pthread_mutex_t *array;
	int i;

	array = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->n_phil);
	i = 0;
	while (i < data->n_phil)
	{
		data->philo[i].n = i + 1;
		pthread_mutex_init(&array[i], NULL);
		data->philo[i].fork_right = &array[i];
		if (i == data->n_phil - 1)
			data->philo[0].fork_left = &array[i];
		else
			data->philo[i + 1].fork_left = &array[i];
		i++;
	}
	i = 0;
	while (i < data->n_phil)
	{
		pthread_create(&(data->philo[i].tid), NULL, routin, &(data->philo[i]));
		i++;
	}
	i = 0;
	while (i < data->n_phil)
	{
		pthread_join(data->philo[i].tid, NULL);
		i++;
	}
}

void parse_variable(char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->n_phil = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->philo = malloc(sizeof(t_philo) * data->n_phil);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	if (argv[5] && data->n_eat == 0)
		return;
	initialize_philo(data);
}

int main(int argc, char **argv)
{
	// pthread_t	tid;

	if (argc != 5 && argc != 6)
		return (0);
	if (!is_valid_integer(argv))
		return (1);
	parse_variable(argv);
	return 0;
}
