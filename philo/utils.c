/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:40:08 by aaghbal           #+#    #+#             */
/*   Updated: 2023/07/24 11:53:56 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	r;
	long long	s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	if (r * s > 2147483647 || r * s < 0)
		return (-1);
	return (r * s);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	if (lst && *lst)
		ft_lstlast(*lst)->next = new;
	else if (lst)
		*lst = new;
}

long long	get_time_of_day(void)
{
	long long		res;
	struct timeval	tmv;

	res = 0;
	gettimeofday(&tmv, NULL);
	res = (tmv.tv_sec * 1000) + (tmv.tv_usec / 1000);
	return (res);
}
