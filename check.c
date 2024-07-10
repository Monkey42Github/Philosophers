/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:16:58 by pschemit          #+#    #+#             */
/*   Updated: 2023/01/10 16:44:19 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if ((num > 2147483647) || (num < -2147483648))
		return (-5);
	return (num);
}

int	ft_len( char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	valide_num(char *a)
{
	int	i;
	int	usless;

	i = 0;
	if (ft_len(a) > 11)
		return (0);
	if ((a[i] == '+') && (a[i + 1]))
		i++;
	while (a[i])
	{
		if ((a[i] < '0') || (a[i] > '9'))
			return (0);
		i++;
	}
	usless = ft_atoi(a);
	if (usless < 0)
		return (0);
	return (1);
}

int	ft_check(int ac, char **av)
{
	int	i;

	if ((ac == 5) || (ac == 6))
	{
		i = 1;
		while (av[i])
		{
			if (!valide_num(av[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
