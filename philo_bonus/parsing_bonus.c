/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:27:06 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/29 14:34:16 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_argument(char *av, t_data *data)
{
	data->j = 0;
	while (av[data->j])
	{
		if (av[data->j] == '+')
			data->j++;
		if (!ft_isdigit(av[data->j]))
			return (1);
		data->j++;
	}
	return (0);
}

void	ft_printf(t_philo *philo, char *str)
{
	sem_wait(philo->data->sem_p2);
	printf("%lld %d %s\n", get_time(philo->data), philo->index, str);
	sem_post(philo->data->sem_p2);
}
