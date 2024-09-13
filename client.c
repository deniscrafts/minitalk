/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denrodri <denrodri@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:17:39 by denrodri          #+#    #+#             */
/*   Updated: 2024/09/13 14:21:47 by denrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_struct	*client_initiate(void)
{
	t_struct	*talk;

	talk = malloc(sizeof(t_struct));
	if (!talk)
	{
		ft_putstr("ERROR!, malloc failed : !\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	talk->pid_client = 0;
	return (talk);
}

void	client_send(t_struct *talk, char *message)
{
	int	bit_displacement;
	int	i;
	int	signal;

	i = -1;
	while (++i <= ft_strlen(message))
	{
		bit_displacement = -1;
		signal = 0;
		while (++bit_displacement < 7)
		{
			if ((message[i] >> bit_displacement) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_server, signal);
			usleep(200);
		}
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_struct	*talk;

	talk = NULL;
	if (argc != 3)
	{
		ft_putstr("ERROR!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = client_initiate();
		talk->pid_server = ft_atoi(argv[1]);
		client_send(talk, argv[2]);
	}
	free(talk);
	return (EXIT_SUCCESS);
}
