/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denrodri <denrodri@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:33:59 by denrodri          #+#    #+#             */
/*   Updated: 2024/09/13 13:53:19 by denrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_struct
{
	int	pid_server;
	int	pid_client;
}				t_struct;

t_struct	*client_start(void);
t_struct	*server_start(void);
void		client_send(t_struct *talk, char *message);
void		server_receive(int boolean);
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
void		ft_putstr(char *str);
void		ft_putnbr(int num);

#endif
