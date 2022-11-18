/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_talk.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:44:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/11/18 22:35:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_TALK_H
#define FT_MINI_TALK_H

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int t_pid;

typedef enum e_type
{
	CLIENT,
	SERVER
} t_type;

typedef struct s_data
{
	t_type				type;
	int 				index_char;
	t_pid 				client;
	char 				c;
	char 				*msg;
	double				progress_vaue;
	double				progress;
	double				progress_max;
	struct sigaction	action;
} t_data;

int str_to_int(char *v, int n);
int ft_strlen(char *txt);
int ft_printf(const char *txt, ...);

#endif
