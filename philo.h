/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:10:26 by pschemit          #+#    #+#             */
/*   Updated: 2023/01/10 15:31:19 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef unsigned long long	t_time;

typedef struct s_args{
	pthread_mutex_t	*fork;
	pthread_mutex_t	memoire;
	int				nb_ph;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_e_ph;
	int				*etat;
}t_args;

typedef struct s_philo{
	pthread_mutex_t	*gauche;
	pthread_mutex_t	*droite;
	pthread_t		thread;
	t_args			*data;
	t_time			last_eat;
	int				nb_time_eat;
	int				index;
	int				*etatphilo;
}t_philo;

t_time	ft_time_ms(void);
int		ft_check(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_mem(t_args *data);
void	simulation(t_args *data, t_philo *tab);
void	*verif_daeth(t_philo *tab);
void	ft_usleep(int n);
void	one_philo(t_philo *tab);
void	usless_one_philo(t_philo *tab);
int		ft_destroy_mutex(t_args data, t_philo *tab);
#endif
