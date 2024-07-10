/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:47:40 by pschemit          #+#    #+#             */
/*   Updated: 2023/01/10 17:15:42 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_init_args(int ac, char **av, t_args *data)
{
	data->nb_ph = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_e_ph = 2000000000;
	if (ac == 6)
		data->nb_e_ph = ft_atoi(av[5]);
	if ((data->nb_ph <= 0)
		|| (data->nb_e_ph == 0))
		return (0);
	data->etat = malloc(sizeof(int));
	data->etat[0] = 0;
	return (1);
}

void	ft_init_philo(t_args *data, t_philo *tab)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->memoire, NULL);
	while (i != data->nb_ph)
	{
		tab[i].data = data;
		pthread_mutex_init(&data->fork[i], NULL);
		tab[i].gauche = &data->fork[i];
		if (i != 0)
			tab[i].droite = &data->fork[i - 1];
		else
			tab[0].droite = &data->fork[data->nb_ph - 1];
		tab[i].index = i + 1;
		tab[i].last_eat = 0;
		tab[i].nb_time_eat = 0;
		tab[i].etatphilo = data->etat;
		i++;
	}
}

int	ft_mem(t_args *data)
{
	int	val;

	pthread_mutex_lock(&data->memoire);
	val = *data->etat;
	pthread_mutex_unlock(&data->memoire);
	return (val);
}

void	*verif_daeth(t_philo *tab)
{
	t_args	*data;
	int		i;
	int		a;

	a = 0;
	data = tab[0].data;
	while (*data->etat == 0)
	{
		pthread_mutex_lock(&data->memoire);
		if ((tab[i].last_eat + data->time_to_die) <= ft_time_ms())
		{
			printf("%lld %d died\n", ft_time_ms(), tab[i].index);
			*tab[i].etatphilo = 1;
		}
		else if (tab[i].nb_time_eat >= data->nb_e_ph && ++a >= data->nb_ph)
			*data->etat = 1;
		pthread_mutex_unlock(&data->memoire);
		if (++i >= data->nb_ph)
		{
			i = 0;
			a = 0;
			ft_usleep(1000);
		}
	}
	return (tab);
}

int	main(int ac, char **av)
{
	t_args	data;
	t_philo	*tab;

	if (!ft_check(ac, av) || !ft_init_args(ac, av, &data))
	{
		printf("Error : Wrong Args !\n");
		return (0);
	}
	data.fork = malloc(sizeof(pthread_mutex_t) * data.nb_ph);
	tab = malloc(sizeof(t_philo) * data.nb_ph);
	ft_init_philo(&data, tab);
	if (data.nb_ph == 1)
	{
		one_philo(tab);
		ft_destroy_mutex(data, tab);
		return (0);
	}
	simulation(&data, tab);
	ft_destroy_mutex(data, tab);
	return (0);
}
