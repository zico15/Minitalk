/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:37:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/17 18:19:15 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_talk.h"

static	void	ft_print_mensagem(int bit, siginfo_t *info, t_mensagem	*m)
{
	if (m->index_char < 8)
		m->c = bit << m->index_char++ | m->c;
	if (m->index_char == 8)
	{
		m->msg[m->index_msg++] = m->c;
		if (m->c == 0)
		{
			write(1, m->msg, m->size);
			m->size = 0;
			m->msg = 0;
			m->index_msg = 0;
			send_msg(info->si_pid, 0);
		}
		m->c = 0;
		m->index_char = 0;
	}
}

static	void	ft_mensagem_size(int bit, t_mensagem *m)
{
	if (m->index_char < 33)
		m->size = bit << m->index_char++ | m->size;
	if (m->index_char == 33)
	{
		if (m->msg)
			free(m->msg);
		m->msg = malloc(sizeof(char) * m->size + 1);
		m->msg[m->size] = 0;
		m->index_char = 0;
	}
}

static void	server_list(int signo, siginfo_t *i, void *context)
{
	if (signo == SIGINT)
	{
		clean_msg(0);
		ft_printf("\nbye bye..\n");
		exit(-1);
	}
	if (get_serve_msg()->id_client && get_serve_msg()->id_client != i->si_pid)
		clean_msg(i->si_pid);
	if (get_serve_msg()->msg)
		ft_print_mensagem((signo - SIGUSR1), i, get_serve_msg());
	else
		ft_mensagem_size((signo - SIGUSR1), get_serve_msg());
}

int	main(void)
{
	t_pid				id;
	struct sigaction	usr_action;
	sigset_t			block_mask;

	sigemptyset (&block_mask);
	usr_action.sa_mask = block_mask;
	sigaddset(&usr_action.sa_mask, SIGUSR1);
	sigaddset(&usr_action.sa_mask, SIGUSR2);
	usr_action.sa_flags = SA_SIGINFO;
	usr_action.sa_sigaction = server_list;
	sigaction(SIGUSR1, &usr_action, NULL);
	sigaction(SIGUSR2, &usr_action, NULL);
	sigaction(SIGINT, &usr_action, NULL);
	id = getpid ();
	ft_printf ("PID SERVER: %i\n", id);
	while (1)
		pause();
	return (0);
}
