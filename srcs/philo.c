/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:04:49 by htaheri           #+#    #+#             */
/*   Updated: 2023/10/08 18:29:11 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/philosophers.h"

void	initialize_philo()
{
	
}

void	parse_variable(char **argv)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	data->n_phil = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->philo = malloc(sizeof(t_philo) * data->n_phil);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	if (argv[5] && data->n_eat == 0)
		return (1);
}



int	main(int argc, char **argv)
{
	pthread_t	tid;

	if (argc != 5 && argc != 6)
		return (0);
	if (!is_valid_integer(argv))
		return (1);
	parse_variable(argv);
	initialize_philo();
}
