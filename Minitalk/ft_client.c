/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:55 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/17 18:22:16 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_talk.h"

static void	handler(int signo)
{
	if (signo == SIGUSR1 && ft_printf("MENSAGEM OK"))
		exit(-1);
}

int	main(int argv, char **argc)
{
	t_pid				id;
	struct sigaction	usr_action;
	sigset_t			block_mask;
	char				*str;

	sigfillset (&block_mask);
	usr_action.sa_handler = handler;
	usr_action.sa_mask = block_mask;
	usr_action.sa_flags = SA_SIGINFO;
	if (signal(SIGUSR1, handler) || signal(SIGUSR2, handler))
		ft_printf("NO SERVER\n");
	if (argv > 1)
	{
		id = str_to_int(argc[1], 0);
		send_bity(id, ft_strlen(argc[2]), 32);
		send_msg(id, argc[2]);
		ft_printf("child_id: %s\n", argc[1]);
		sleep(5);
	}
	return (0);
}
