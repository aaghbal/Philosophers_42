/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:28:19 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 12:12:03 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	int				i;
	int				j;
	int				n_philo;
	int				n_of_eat;
	long long		time_t_d;
	long long		time_t_e;
	long long		time_t_s;
	long long		start;
	pthread_t		*thr;
	pthread_mutex_t	*mtx;
	pthread_mutex_t	mtx_print;
	pthread_mutex_t	mtx_flags;
}t_data;

typedef struct s_philo
{
	int				index;
	int				n_eat;
	long long		time_die;
	long long		time_eat;
	long long		time_slep;
	int				flags;
	long long		l_eat;
	long long		s_time;
	pthread_mutex_t	mtx_neat;
	pthread_mutex_t	mtx_leat;
	t_data			*data;
	struct s_philo	*next;
}t_philo;

int			check_argument(char *av, t_data *data);
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo		*ft_lstlast(t_philo *lst);
long long	get_time_of_day(void);
long long	get_time(t_philo *philo);
void		create_philo(t_data *data);
void		*routine(void *philo);
void		create_philo(t_data *data);
void		create_mtx(t_philo *philo);
void		create_thr(t_philo *philo, t_data *data);
t_philo		*init_philo(t_data *data);
int			ft_init_data(t_data *data, char **av);
void		check_death(t_philo *philo);
void		ft_free(t_philo *philo);
int			check_n_eat(t_philo *philo);
#endif
