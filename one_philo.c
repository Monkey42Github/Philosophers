/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:11:38 by pschemit          #+#    #+#             */
/*   Updated: 2023/01/10 16:20:01 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	one_philo(t_philo *tab)
{
	pthread_t	verif;

	pthread_create(&verif, NULL, (void *(*)(void *))usless_one_philo, tab);
	pthread_join(verif, NULL);
	ft_usleep(tab->data->time_to_die);
	printf("%lld %d died\n", ft_time_ms(), 1);
}

void	usless_one_philo(t_philo *tab)
{
	pthread_mutex_lock(tab->gauche);
	printf("%lld %d has taken a fork\n", ft_time_ms(), tab->index);
	pthread_mutex_unlock(tab->gauche);
}
