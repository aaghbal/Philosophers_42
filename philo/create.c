/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:50:25 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 15:39:51 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philo(t_philo *philo)
{
	while (philo)
	{
		pthread_mutex_lock(&philo->data->mtx_flags);
		philo->flags = 1;
		pthread_mutex_unlock(&philo->data->mtx_flags);
		philo = philo->next;
	}
}

void	create_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = NULL;
	i = 0;
	data->i = 1;
	while (i < data->n_philo)
	{
		ft_lstadd_back(&philo, init_philo(data));
		i++;
		data->i++;
	}
	data->mtx = malloc(sizeof(pthread_mutex_t) * sizeof(data->n_philo));
	if (!data->i)
		return ;
	create_mtx(philo);
	create_thr(philo, data);
	check_death(philo);
	kill_philo(philo);
	i = -1;
	pthread_mutex_unlock(&philo->data->mtx_print);
	while (++i < data->n_philo)
		pthread_join(data->thr[i], NULL);
	ft_free(philo);
}

void	create_mtx(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_mutex_init(&philo->data->mtx[i], NULL);
		i++;
	}
}

void	create_thr(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_create(&data->thr[i], NULL, &routine, philo);
		usleep((data->time_t_e / 3) + 100);
		philo = philo->next;
		i++;
	}
}
