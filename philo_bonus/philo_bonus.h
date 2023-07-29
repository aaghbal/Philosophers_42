/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:44:37 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 12:09:06 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_data
{
	int			i;
	int			j;
	int			n_philo;
	int			n_of_eat;
	int			num_eat;
	long long	time_t_d;
	long long	time_t_e;
	long long	time_t_s;
	long long	start;
	int			index;
	pid_t		*pid;
	sem_t		*sem_f;
	sem_t		*sem_eat;
	sem_t		*sem_p;
	sem_t		*sem_p2;
}t_data;

typedef struct s_philo
{
	int			index;
	int			n_eat;
	int			flags;
	pthread_t	thr;
	long long	l_eat;
	t_data		*data;
}t_philo;

void		create_proc(t_data *data);
int			ft_init_data(t_data *data, char **av);
void		*routine(t_philo *philo);
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
long long	get_time_of_day(void);
long long	get_time(t_data *data);
int			check_argument(char *av, t_data *data);
void		init_philo(t_philo *philo, t_data *data, int i);
void		ft_printf(t_philo *philo, char *str);
void		kill_all_proc(t_data *data);
void		wait_all_proc(t_data *data);
#endif
