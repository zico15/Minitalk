/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_talk.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:44:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/17 18:21:28 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_TALK_H
# define FT_MINI_TALK_H

# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef int	t_pid;

typedef struct s_mensagem
{
	int				index_char;
	int				index_msg;
	int				size;
	t_pid			id_client;
	unsigned char	c;
	unsigned char	*msg;
}	t_mensagem;

int			str_to_int(char *v, int n);
void		send_msg(pid_t id, char *txt);
int			bity_to_char(int signo, int index);
int			ft_strlen(char *txt);
void		send_bity(pid_t id, int v, int len);
t_mensagem	*get_serve_msg(void);
int			clean_msg(t_pid	id_client);
int			ft_printf(const char *txt, ...);
#endif
