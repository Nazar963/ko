/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:20:32 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/02 18:44:49 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	if (ft_isdigit_new(av[1]) && ft_isdigit_new(av[2])
		&& ft_isdigit_new(av[3]) && ft_isdigit_new(av[4]))
	{
		if (ac == 6)
		{
			if (ft_isdigit_new(av[5]))
				return (TRUE);
			else
				return (FALSE);
		}
		else
			return (TRUE);
	}
	return (0);
}

t_loco	*initialize(int ac, char **av, t_loco *loco)
{
	int	i;

	i = 0;
	loco->flag_death = 0;
	loco->n_philos = ft_atoi(av[1]);
	loco->t_die = ft_atoi(av[2]);
	loco->t_eat = ft_atoi(av[3]);
	loco->t_sleep = ft_atoi(av[4]);
	loco->start_time = fetch_time();
	while (i < loco->n_philos)
	{
		loco->philo[i].n_meals = ft_sp_atoi(ac, av);
		loco->philo[i].go = fetch_time();
		i++;
	}
	loco->forks = (pthread_mutex_t *)malloc(loco->n_philos
			* sizeof(pthread_mutex_t));
	if (!loco->forks)
		return (NULL);
	if (pthread_mutex_init(&loco->print, NULL) != 0)
		return (NULL);
	return (loco);
}
