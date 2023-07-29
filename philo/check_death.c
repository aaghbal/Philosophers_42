/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:55:48 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 11:47:56 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_n_eat(t_philo *philo)
{
	int	c;
	int	n;
	int	n_phi;

	c = 0;
	n = 0;
	n_phi = philo->data->n_philo;
	while (philo)
	{
		pthread_mutex_lock(&philo->mtx_neat);
		if (philo->n_eat >= philo->data->n_of_eat)
			c++;
		pthread_mutex_unlock(&philo->mtx_neat);
		pthread_mutex_lock(&philo->data->mtx_flags);
		if (philo->flags == 1)
			n++;
		pthread_mutex_unlock(&philo->data->mtx_flags);
		philo = philo->next;
	}
	if (c == n_phi || n == n_phi)
		return (1);
	return (0);
}

void	check_death(t_philo *philo)
{
	t_philo	*ph;
	t_philo	*ph2;

	ph = philo;
	while (1)
	{
		if (philo == NULL)
			philo = ph;
		ph2 = ph;
		pthread_mutex_lock(&philo->mtx_leat);
		if (get_time(philo) - philo->l_eat >= philo->time_die)
		{
			pthread_mutex_unlock(&philo->mtx_leat);
			pthread_mutex_lock(&philo->data->mtx_print);
			printf("%lld %d died\n", get_time(philo), philo->index);
			break ;
		}
		else if (philo->data->n_of_eat && check_n_eat(ph2))
		{
			pthread_mutex_unlock(&philo->mtx_leat);
			break ;
		}
		pthread_mutex_unlock(&philo->mtx_leat);
		philo = philo->next;
	}
}
