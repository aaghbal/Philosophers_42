/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:46:47 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 11:47:46 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	break_thr(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->mtx_flags);
	if (ph->flags == 1)
	{
		pthread_mutex_unlock(&ph->data->mtx_flags);
		return (1);
	}
	pthread_mutex_unlock(&ph->data->mtx_flags);
	return (0);
}

void	ft_usleep(t_philo *philo, long long tim)
{
	long long	s;

	s = get_time(philo);
	while ((get_time(philo) - s) * 1000 < tim)
		usleep(100);
}

int	check_onethr(t_philo *philo)
{
	if (philo->data->n_philo == 1)
	{
		ft_usleep(philo, philo->time_slep * 1000);
		pthread_mutex_unlock(&philo->data->mtx[philo->index - 1]);
		return (1);
	}
	return (0);
}

void	ft_printf(t_philo *philo, char *str, int c)
{
	if (c == 1)
	{
		pthread_mutex_lock(&philo->mtx_leat);
		philo->l_eat = get_time(philo);
		pthread_mutex_unlock(&philo->mtx_leat);
		pthread_mutex_lock(&philo->mtx_neat);
		philo->n_eat++;
		pthread_mutex_unlock(&philo->mtx_neat);
	}
	pthread_mutex_lock(&philo->data->mtx_print);
	pthread_mutex_lock(&philo->data->mtx_flags);
	if (philo->flags == 0)
		printf("%lld %d %s\n", get_time(philo), philo->index, str);
	pthread_mutex_unlock(&philo->data->mtx_flags);
	pthread_mutex_unlock(&philo->data->mtx_print);
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->index % 2 == 1)
		usleep(50);
	while (1)
	{
		if (break_thr(ph))
			break ;
		pthread_mutex_lock(&ph->data->mtx[ph->index - 1]);
		ft_printf(ph, "has taken a fork", 0);
		if (check_onethr(ph))
			break ;
		pthread_mutex_lock(&ph->data->mtx[(ph->index) % ph->data->n_philo]);
		ft_printf(ph, "has taken a fork", 0);
		ft_printf(ph, "is eating", 1);
		ft_usleep(ph, ph->time_eat * 1000);
		pthread_mutex_unlock(&ph->data->mtx[ph->index - 1]);
		pthread_mutex_unlock(&ph->data->mtx[ph->index % ph->data->n_philo]);
		ft_printf(ph, "is sleeping", 0);
		ft_usleep(ph, ph->time_slep * 1000);
		ft_printf(ph, "is thinking", 0);
	}
	return (NULL);
}
