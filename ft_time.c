/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:15:33 by pschemit          #+#    #+#             */
/*   Updated: 2023/01/10 17:16:07 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_time	ft_time_ms(void)
{
	static t_time	start = 0;
	t_time			current;
	t_time			res;
	struct timeval	time;

	gettimeofday(&time, NULL);
	current = (time.tv_sec * (long)1000) + (time.tv_usec / (long)1000);
	if (start == 0)
		start = current;
	res = current - start;
	return (res);
}

void	ft_usleep(int n)
{
	t_time	end_time;

	end_time = ft_time_ms() + n;
	while (ft_time_ms() < end_time)
		usleep(400);
}

int	ft_destroy_mutex(t_args data, t_philo *tab)
{
	int	i;

	i = 0;
	while (i < data.nb_ph)
	{
		pthread_mutex_destroy(&data.fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data.memoire);
	free(data.fork);
	free(tab);
	return (0);
}
