/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:17:25 by htaheri           #+#    #+#             */
/*   Updated: 2023/10/31 15:39:46 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include "../libs/libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define MAX_INT INT_MAX
# define MIN_INT INT_MIN

typedef struct s_philo
{
	int					n;
	int					eat_counter;
	long long			last_eat;
	struct s_data		*data;
	pthread_t			tid;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		eating_mtx;
}t_philo;

typedef struct s_data
{
	long long			t_start;
	int					n_phil;
	int					t_eat;
	int					t_die;
	int					t_sleep;
	int					n_eat;
	int					someone_died;
	int					someone_finished;
	pthread_mutex_t		mtx_someone_died;
	int					ph_stop;
	struct s_philo		*philo;
	pthread_mutex_t		print;
	pthread_mutex_t		dead;
	pthread_mutex_t		finished;
	pthread_mutex_t		stop;
}t_data;

int				is_valid_integer(char **args);
long long		current_time(void);
void			*check_status(void *args);
void			*routin(void *arg);
void			print(t_philo *philo, char *str);
int				is_someone_dead(t_data *data);
void			pause_time(int t);
void			exit_philos(t_data *data);
int				eat_enough(t_data *data);
int				has_someone_eaten_enough(t_data *data);
void			set_someone_eaten_enough(t_data *data);
int				is_someone_finished(t_data *data);

#endif