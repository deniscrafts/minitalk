/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denrodri <denrodri@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:33:40 by denrodri          #+#    #+#             */
/*   Updated: 2024/09/11 18:54:05 by denrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_struct	*server_initiate(void)
{
	t_struct	*talk;

	talk = malloc(sizeof(t_struct));
	if (!talk)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	talk -> pid_server = 0;
	talk -> pid_client = 0;
	return (talk);
}

void	server_recieve(int boolean)
{
	static int	bit_displacement = 0;
	static char	letter = 0;

	letter += ((boolean & 1) << bit_displacement++);
	if (bit_displacement == 7)
	{
		write(1, &letter, 1);
		if (!letter)
			write(1, "\n", 1);
		bit_displacement = 0;
		letter = 0;
	}
	return ;
}

void	server_loop(t_struct *talk)
{
	while (1)
	{
		if ((signal(SIGUSR1, server_recieve) == SIG_ERR)
			|| (signal(SIGUSR2, server_recieve) == SIG_ERR))
		{
			ft_putstr("ERROR!\n");
			free(talk);
			exit(EXIT_FAILURE);
		}
		sleep(2);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_struct	*talk;

	(void)argv;
	talk = NULL;
	if (argc != 1)
	{
		ft_putstr("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_initiate();
		talk -> pid_server = getpid();
		ft_putstr("PID: ");
		ft_putnbr(talk -> pid_server);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	return (EXIT_SUCCESS);
}
