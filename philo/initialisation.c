/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:49:29 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/29 14:42:34 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	pthread_mutex_init(&philo->mtx_leat, NULL);
	pthread_mutex_init(&philo->mtx_neat, NULL);
	philo->data = data;
	philo->time_die = data->time_t_d;
	philo->time_eat = data->time_t_e;
	philo->time_slep = data->time_t_s;
	philo->n_eat = 0;
	philo->index = data->i;
	philo->l_eat = 0;
	philo->s_time = 0;
	philo->flags = 0;
	philo->next = NULL;
	return (philo);
}

int	ft_init_data(t_data *data, char **av)
{
	pthread_mutex_init(&data->mtx_print, NULL);
	pthread_mutex_init(&data->mtx_flags, NULL);
	data->thr = malloc(sizeof(pthread_t) * data->n_philo);
	if (!data->thr)
		return (1);
	data->start = get_time_of_day();
	data->n_philo = ft_atoi(av[1]);
	data->time_t_d = ft_atoi(av[2]);
	data->time_t_e = ft_atoi(av[3]);
	data->time_t_s = ft_atoi(av[4]);
	if (data->n_philo == -1 || data->time_t_d == -1 || data->time_t_e == -1
		|| data->time_t_s == -1)
		return (1);
	if (av[5])
		data->n_of_eat = ft_atoi(av[5]);
	else
		data->n_of_eat = 0;
	return (0);
}
