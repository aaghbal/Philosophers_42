/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:45:22 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/29 14:35:05 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_all_proc(t_data *data)
{
	data->i = 1;
	while (data->i < data->n_philo)
	{
		waitpid(-1, NULL, 0);
		data->i++;
	}
}

void	kill_all_proc(t_data *data)
{
	data->i = 0;
	while (data->i < data->n_philo)
	{
		kill(data->pid[data->i], SIGKILL);
		data->i++;
	}
	free(data->pid);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		s;

	data.i = 1;
	if (ac == 5 || ac == 6)
	{
		while (av[data.i])
		{
			if (!av[data.i][0] || check_argument(av[data.i], &data))
				return (printf("Error arguments\n"));
			data.i++;
		}
		if (ft_init_data(&data, av))
			return (printf("error number\n"));
		if (data.n_philo == 0 || (data.n_of_eat == 0 && av[5]))
			return (0);
		create_proc(&data);
		waitpid(-1, &s, 0);
		if (WEXITSTATUS(s) == 0)
			wait_all_proc(&data);
		kill_all_proc(&data);
	}
	else
		write(2, "Error arguments\n", 16);
}
