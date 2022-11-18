/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:37:35 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/18 22:41:30 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_talk.h"

void 	send_signo(t_pid pid);

t_data *data()
{
	static t_data d;

	return (&d);
}

static void	listening(int signo, siginfo_t *i, void *v)
{
	(void) v;
	if (data()->type == SERVER)
	{
		if (data()->client != i->si_pid)
		{
			data()->client = i->si_pid;
			data()->index_char = 0;
			data()->c = 0;
		}
		data()->c = (signo == SIGUSR2) << data()->index_char++ | data()->c;
		if (data()->index_char >= 8)
		{
			write(1, &data()->c, 1);
			data()->index_char = 0;
			data()->c = 0;
		}
		if (kill(i->si_pid, SIGUSR1) == -1)
			exit(0);
	}
	else
		send_signo(i->si_pid);
}

void print_progress_bar()
{
	int	i;
	int	p;

	i = -1;
	p = (data()->progress_vaue * 5.0);
	system("clear");
	while (++i < 20)
	{
		if (i > p)
			ft_printf("⬜");
		else
			ft_printf("🟦");
	}
	p *= 5;
	if (p >= 100)
		p = 100;
	ft_printf(" %i%%\n", p);
	data()->progress_vaue += data()->progress;
}

void send_signo(t_pid pid)
{
	char	c;

	//print_progress_bar();
	if (!data()->msg)
		exit(0);
	c = *data()->msg;
	if ((c >> data()->index_char++ & 1))
	{	
		if(kill(pid, SIGUSR2) == -1)
			exit(0);
	}
	else if (kill(pid, SIGUSR1) == -1)
		exit(0);
	if (!(*data()->msg))
	{
		data()->msg = NULL;
		return ;
	}
	if (data()->index_char >= 8)
	{
		data()->index_char = 0;
		data()->msg++;
	}	
}

int	main(int argc, char **argv)
{
	sigaddset(&data()->action.sa_mask, SIGUSR1);
	sigaddset(&data()->action.sa_mask, SIGUSR2);
	data()->action.sa_flags = SA_SIGINFO;
	data()->action.sa_sigaction = listening;
	sigaction(SIGUSR1, &data()->action, NULL);
	sigaction(SIGUSR2, &data()->action, NULL);
	if (argc == 1)
	{
		data()->type = SERVER;
		ft_printf ("PID SERVER: %i\n", getpid ());		
	}
	else if (argc > 2)
	{
		data()->client = str_to_int(argv[1], 0);
		data()->msg = argv[2];	
		data()->progress = (20.0 / ((double)ft_strlen(data()->msg) * 8.0));
		data()->progress_max = 20;
		send_signo(data()->client);
	}
	while (1)
		pause();
	return (0);
}
