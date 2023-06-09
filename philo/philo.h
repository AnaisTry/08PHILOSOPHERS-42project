/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:27:34 by angassin          #+#    #+#             */
/*   Updated: 2023/06/14 18:05:12 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*									[Includes]								*/

# include <pthread.h>
# include <stdatomic.h>
# include <limits.h>
// printf
# include <stdio.h>
// malloc, free
# include <stdlib.h>
// usleep
# include <unistd.h>
// gettimeofday
# include <sys/time.h>

/*									[Macros]								*/

# define OK 0
# define EVEN 0
# define INFINITE -1

/*									[Typedefs]								*/

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

typedef struct s_symposium	t_symposium;
typedef struct s_philo
{
	int						id;
	pthread_t				p_id;
	_Atomic time_t			last_meal;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	atomic_int				nb_meals;
	t_symposium				*dinner;
}							t_philo;

struct						s_symposium
{
	int						nb_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	atomic_int				max_nb_meals;
	int						all_full;
	time_t					start;
	t_philo					*philos;
	pthread_mutex_t			*forks;
	pthread_mutex_t			*death;
	t_bool					dead;
	pthread_mutex_t			*print;
};

/*									[Src]									*/

// init.c
int		symposium_init(int argc, char **argv, t_symposium *s);

// philo.c
int		thread_create(t_symposium *s);
int		thread_wait(t_symposium *s);

/*									[Utils]									*/

// utils.c
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
time_t	get_time(void);
void	ft_usleep(time_t time);
t_bool	someone_is_dead(t_symposium *s);

// error.c
int		error_exit(t_symposium *s, char *message, int status);
#endif
