/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:51:58 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/29 14:30:43 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_init_data(t_data *data, char **av)
{
	data->start = get_time_of_day();
	data->index = 1;
	data->n_philo = ft_atoi(av[1]);
	data->time_t_d = ft_atoi(av[2]);
	data->time_t_e = ft_atoi(av[3]);
	data->time_t_s = ft_atoi(av[4]);
	if (data->n_philo == -1 || data->time_t_d == -1 || data->time_t_e == -1
		|| data->time_t_s == -1)
		return (1);
	data->pid = malloc(sizeof(pid_t) * data->n_philo);
	if (!data->pid)
		return (1);
	data->sem_f = sem_open("/semaphore", O_CREAT, 0644, data->n_philo);
	data->sem_p2 = sem_open("/print2", O_CREAT, 0644, 1);
	data->sem_p = sem_open("/print", O_CREAT, 0644, 1);
	data->sem_eat = sem_open("/eat", O_CREAT, 0644, 1);
	sem_unlink("/semaphore");
	sem_unlink("/print2");
	sem_unlink("/print");
	sem_unlink("/eat");
	if (av[5])
		data->n_of_eat = ft_atoi(av[5]);
	else
		data->n_of_eat = 0;
	return (0);
}

void	init_philo(t_philo *philo, t_data *data, int i)
{
	philo->data = data;
	philo->index = i;
	philo->n_eat = 0;
	philo->l_eat = 0;
	philo->flags = 0;
}
