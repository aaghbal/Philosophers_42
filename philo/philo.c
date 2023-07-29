/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:27:59 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/29 14:30:02 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.i = 1;
	if (ac == 5 || ac == 6)
	{
		while (av[data.i])
		{
			if (!av[data.i][0])
				printf("empty string\n");
			if (!av[data.i][0] || check_argument(av[data.i], &data))
				return (0);
			data.i++;
		}
		if (ft_init_data(&data, av))
			return (printf("error number\n"));
		if (data.n_philo == 0 || (data.n_of_eat == 0 && av[5]))
			return (0);
		create_philo(&data);
	}
	else
		write(2, "Error arguments\n", 16);
}
