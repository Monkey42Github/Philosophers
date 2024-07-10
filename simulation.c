/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:10:59 by pschemit          #+#    #+#             */
/*   Updated: 2023/01/10 16:44:56 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	penser(t_philo *tab)
{
	if (ft_mem(tab->data) == 0)
		printf("%lld %d is thinking\n", ft_time_ms(), tab->index);
}

void	dormir(t_philo *tab)
{
	if (ft_mem(tab->data) == 0)
	{
		printf("%lld %d is sleeping\n", ft_time_ms(), tab->index);
		ft_usleep(tab->data->time_to_sleep);
	}
}

void	manger(t_philo *tab)
{
	pthread_mutex_lock(tab->gauche);
	if (ft_mem(tab->data) == 0)
		printf("%lld %d has taken a fork\n", ft_time_ms(), tab->index);
	pthread_mutex_lock(tab->droite);
	if (ft_mem(tab->data) == 0)
		printf("%lld %d has taken a fork\n", ft_time_ms(), tab->index);
	tab->nb_time_eat += 1;
	tab->last_eat = ft_time_ms();
	if (ft_mem(tab->data) == 0)
		printf("%lld %d is eating\n", tab->last_eat, tab->index);
	ft_usleep(tab->data->time_to_eat);
	pthread_mutex_unlock(tab->gauche);
	pthread_mutex_unlock(tab->droite);
}

void	*routine(t_philo *tab)
{
	if (tab->index % 2)
		ft_usleep(tab->data->time_to_eat / 3);
	while (ft_mem(tab->data) == 0)
	{
		manger(tab);
		dormir(tab);
		penser(tab);
	}
	return (tab);
}

void	simulation(t_args *data, t_philo *tab)
{
	pthread_t	verif;
	int			i;

	i = 0;
	while (i < data->nb_ph)
	{
		pthread_create(&tab[i].thread, NULL, \
		(void *(*)(void *))routine, &tab[i]);
		i++;
	}
	pthread_create(&verif, NULL, (void *(*)(void *))verif_daeth, tab);
	pthread_join(verif, NULL);
	i = 0;
	while (i < data->nb_ph)
	{
		pthread_join(tab[i].thread, NULL);
		i++;
	}
}
