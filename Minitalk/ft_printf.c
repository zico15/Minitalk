/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:37:18 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/16 20:17:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_talk.h"

static char	*convert_base(char *str, int n, char *base, int size_base);
static int	read_flags(const char *txt, va_list	*arg);

int	str_to_int(char *v, int n)
{
	if (v && *v >= '0' && *v <= '9')
	{
		n = (n * 10) + (*v - '0');
		v++;
		return (str_to_int(v, n));
	}
	return (n);
}

int	ft_strlen(char *txt)
{
	if (*txt)
		return (1 + ft_strlen(++txt));
	return (0);
}

int	ft_printf(const char *txt, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, txt);
	while (txt && *txt)
	{
		if (*txt == '%' && txt++)
			i += read_flags(txt, &arg);
		else
			i += write(1, txt, 1);
		txt++;
	}
	va_end(arg);
	return (i);
}

static int	read_flags(const char *txt, va_list	*arg)
{
	char	*str;
	char	str_int[20];
	int		n;

	str = 0;
	n = 0;
	str_int[0] = '-';
	if (*txt == 's')
	{
		str = va_arg(*arg, char *);
		return (write(1, str, ft_strlen(str)));
	}
	else if (*txt == '%')
		return (write(1, "%%", 1));
	else if (*txt == 'i' || *txt == 'd')
	{
		n = va_arg(*arg, int);
		convert_base(&(str_int[n < 0]), n, "0123456789", 10);
		return (write(1, str_int, ft_strlen(str_int)));
	}
	return (0);
}

static char	*convert_base(char *str, int n, char *base, int size_base)
{
	if (n <= -10 || n >= 10)
		str = convert_base(str, (n / size_base), base, size_base);
	*str++ = base[(n % size_base) * ((n > 0) - (n < 0))];
	*str = 0;
	return (str);
}
