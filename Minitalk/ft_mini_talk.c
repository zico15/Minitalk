/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_talk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:23:18 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/17 18:22:24 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_talk.h"

void	send_bity(pid_t id, int v, int len)
{
	int	i;

	i = -1;
	while (++i < len && kill (id, ((v >> i & 1) + SIGUSR1)))
		usleep(11);
}

void	send_msg(pid_t id, char *txt)
{
	while (txt && *txt)
		send_bity (id, *txt++, 8);
	send_bity (id, 0, 8);
}

int	clean_msg(t_pid	id_client)
{
	get_serve_msg()->id_client = id_client;
	get_serve_msg()->index_char = 0;
	get_serve_msg()->index_msg = 0;
	if (get_serve_msg()->msg)
		free(get_serve_msg()->msg);
	return (1);
}

t_mensagem	*get_serve_msg(void)
{
	static t_mensagem	m;

	return (&m);
}
