/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:04:49 by htaheri           #+#    #+#             */
/*   Updated: 2023/11/05 17:58:26 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_thread(t_data *data)
{
	int				i;
	pthread_t		check;

	i = 0;
	data->someone_died = 0;
	data->someone_finished = 0;
	while (i < data->n_phil)
	{
		data->philo[i].last_eat = current_time();
		if (pthread_create(&(data->philo[i].tid), NULL,
				routin, &(data->philo[i])) != 0)
		{
			perror("pthread_create");
			return ;
		}
		i++;
	}
	pthread_create(&check, NULL, check_status, data);
	i = 0;
	while (i < data->n_phil)
		pthread_join(data->philo[i++].tid, NULL);
	pthread_join(check, NULL);
}

pthread_mutex_t	*initialize_philo(t_data *data)
{
	int				i;
	pthread_mutex_t	*fork_array;

	i = 0;
	fork_array = malloc(sizeof(pthread_mutex_t) * data->n_phil);
	if (!fork_array)
		perror("Memory allocation failed");
	while (i < data->n_phil)
	{
		data->philo[i].n = i + 1;
		data->philo[i].eat_counter = 0;
		data->philo[i].data = data;
		data->philo[i].fork_right = &fork_array[i];
		pthread_mutex_init(&fork_array[i], NULL);
		pthread_mutex_init(&(data->philo[i].eating_mtx), NULL);
		if (i == data->n_phil - 1)
			data->philo[0].fork_left = &fork_array[i];
		else
			data->philo[i + 1].fork_left = &fork_array[i];
		i++;
	}
	data->t_start = current_time();
	start_thread(data);
	return (fork_array);
}

void	free_datas(pthread_mutex_t *forks, t_data *data, t_philo *philo)
{
	free(forks);
	free(data);
	free(philo);
}

void	parse_variable(char **argv)
{
	t_data			*data;
	pthread_mutex_t	*forks;

	data = malloc(sizeof(t_data));
	if (!data)
		perror("Memory allocation failed");
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->stop, NULL);
	pthread_mutex_init(&data->finished, NULL);
	pthread_mutex_init(&data->mtx_someone_died, NULL);
	data->n_phil = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_eat = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_phil);
	if (!data->philo)
		perror("Memory allocation failed");
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	if (argv[5] && data->n_eat == 0)
		return ;
	forks = initialize_philo(data);
	free_datas(forks, data, data->philo);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (!is_valid_integer(argv))
		return (1);
	parse_variable(argv);
	return (0);
}
