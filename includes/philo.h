/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:19:15 by melfersi          #+#    #+#             */
/*   Updated: 2024/05/15 16:20:53 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>


typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				philo_must_eat;
	bool			dead;
	pthread_t		death_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	struct timeval	start;
}				t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_meal;
	pthread_mutex_t	death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}				t_philo;

//_____________________Prototypes_____________________//

int		init_data(t_data *data, int ac, char **av);
int		init_philo(t_data *data);
void	*routine(void *philo);
long	get_time(t_data *data);
void	print_msg(t_data *data, int id, char *msg);
void	*check_death(void *philo);
void	get_fork(t_philo *p);
void	drop_fork(t_philo *p);
void	ft_usleep(long time);

#endif
