/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:02:29 by angassin          #+#    #+#             */
/*   Updated: 2023/05/31 10:23:31 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	symposium_init(int argc, char **argv, t_symposium *s)
{
	s->nb_philo = ft_atoi(argv[1]);
	s->philos = malloc(sizeof(s->philos) * s->nb_philo);
	s->forks = malloc(sizeof(s->forks) * s->nb_philo);
	s->time_to_die = ft_atoi(argv[2]);
	s->time_to_eat = ft_atoi(argv[3]);
	s->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		s->nb_meals = ft_atoi(argv[5]);
	return (0);
}