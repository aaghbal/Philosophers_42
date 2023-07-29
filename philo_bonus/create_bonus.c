/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:06 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 15:36:17 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		sem_wait(philo->data->sem_p);
		if (get_time(philo->data) - philo->l_eat >= philo->data->time_t_d
			&& !philo->data->n_of_eat)
		{
			printf("%lld %d died\n", get_time(philo->data), philo->index);
			free(philo);
			exit(1);
		}
		else if (philo->data->n_of_eat && philo->n_eat >= philo->data->n_of_eat)
		{
			sem_post(philo->data->sem_p);
			free(philo);
			exit(0);
		}
		sem_post(philo->data->sem_p);
	}
	return (NULL);
}

void	create_proc(t_data *data)
{
	t_philo	*philo;

	data->i = 1;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return ;
	while (data->i <= data->n_philo)
	{
		data->pid[data->i - 1] = fork();
		if (data->pid[data->i - 1] == 0)
		{
			init_philo(philo, data, data->i);
			pthread_create(&philo->thr, NULL, &check_death, philo);
			while (1)
				routine(philo);
		}
		usleep(100);
		data->i++;
	}
}
