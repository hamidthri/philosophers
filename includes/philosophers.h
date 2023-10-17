/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:17:25 by htaheri           #+#    #+#             */
/*   Updated: 2023/10/17 17:07:18 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "../libs/libft/libft.h"
# include <limits.h>
# include <pthread.h>

# define MAX_INT INT_MAX
# define MIN_INT INT_MIN

typedef struct s_philo
{
	int					n;
	struct s_data		*data;
	pthread_t			tid;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
}t_philo;

typedef struct s_data
{
	int					n_phil;
	int					t_eat;
	int					t_die;
	int					t_sleep;
	int					n_eat;
	t_philo				*philo;
}t_data;

int	is_valid_integer(char **args);

#endif