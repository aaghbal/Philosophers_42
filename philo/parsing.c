/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:03:29 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 11:47:27 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argument(char *av, t_data *data)
{
	data->j = 0;
	while (av[data->j])
	{
		if (av[data->j] == '+')
			data->j++;
		if (!ft_isdigit(av[data->j]))
		{
			write(2, "Error arguments\n", 16);
			return (1);
		}
		data->j++;
	}
	return (0);
}

long long	get_time(t_philo *philo)
{
	long long		res;
	struct timeval	tmv;

	res = 0;
	gettimeofday(&tmv, NULL);
	res = (tmv.tv_sec * 1000) + (tmv.tv_usec / 1000) - philo->data->start;
	return (res);
}

void	ft_free(t_philo *philo)
{
	t_philo	*tmp;
	t_data	*data;
	int		i;

	i = 0;
	data = philo->data;
	while (i < data->n_philo)
	{
		tmp = philo;
		pthread_mutex_destroy(&(philo->mtx_leat));
		pthread_mutex_destroy(&(philo->mtx_neat));
		pthread_mutex_destroy(&(data->mtx[i++]));
		philo = philo->next;
		free(tmp);
	}
	free(data->mtx);
	free(data->thr);
	pthread_mutex_destroy(&data->mtx_flags);
	pthread_mutex_destroy(&data->mtx_print);
}
