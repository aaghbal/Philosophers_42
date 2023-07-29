/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:59:22 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 08:19:02 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//
void	*routine(t_philo *philo)
{
	sem_wait(philo->data->sem_f);
	ft_printf(philo, "has taken a fork");
	sem_wait(philo->data->sem_f);
	ft_printf(philo, "has taken a fork");
	philo->l_eat = get_time(philo->data);
	ft_printf(philo, "is eating");
	usleep(philo->data->time_t_e * 1000);
	sem_post(philo->data->sem_f);
	sem_post(philo->data->sem_f);
	sem_wait(philo->data->sem_eat);
	philo->n_eat++;
	sem_post(philo->data->sem_eat);
	ft_printf(philo, "is sleeping");
	usleep(philo->data->time_t_s * 1000);
	ft_printf(philo, "is thinking");
	return (NULL);
}
