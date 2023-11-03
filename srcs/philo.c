/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:04:49 by htaheri           #+#    #+#             */
/*   Updated: 2023/11/03 17:02:33 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start_thread(t_data *data)
{
	int				i;
	pthread_t		check;

	i = 0;
	while (i < data->n_phil)
	{
		data->philo[i].last_eat = current_time();
		pthread_mutex_init(&(data->philo[i].eating_mtx), NULL);

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

void	initialize_philo(t_data *data)
{
	int				i;
	pthread_mutex_t	*fork_array;

	i = 0;
	fork_array = malloc(sizeof(pthread_mutex_t) * data->n_phil);
	while (i < data->n_phil)
	{
		data->philo[i].n = i + 1;
		data->philo[i].eat_counter = 0;
		data->philo[i].data = data;
		data->philo[i].fork_right = &fork_array[i];
		pthread_mutex_init(&fork_array[i], NULL);
		if (i == data->n_phil - 1)
			data->philo[0].fork_left = &fork_array[i];
		else
			data->philo[i + 1].fork_left = &fork_array[i];
		i++;
	}
	// ft_bzero(data, sizeof(t_data));
	data->t_start = current_time();
	data->someone_died = 0;
	start_thread(data);
}

void	parse_variable(char **argv)
{
	t_data	*data;

	/* dont forget to protect this if malloc fails*/
	data = malloc(sizeof(t_data));
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->stop, NULL);
	data->n_phil = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_eat = 0;

	/* dont forget to protect this if malloc fails*/
	data->philo = malloc(sizeof(t_philo) * data->n_phil);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	if (argv[5] && data->n_eat == 0)
		return ;
	initialize_philo(data);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!is_valid_integer(argv))
		return (1);
	parse_variable(argv);
	return (0);
}
