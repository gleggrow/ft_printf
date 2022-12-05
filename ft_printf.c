/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleggrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:55:34 by gleggrow          #+#    #+#             */
/*   Updated: 2021/12/27 11:27:23 by gleggrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_x_util(char *remainder)
{
	int	count;
	int	i;

	i = ft_strlen(remainder) - 1;
	count = ft_strlen(remainder);
	while (i != -1)
	{
		ft_putchar_fd(remainder[i], 1);
		i--;
	}
	free(remainder);
	return (count);
}

int	print_c(va_list params)
{
	int	c;

	c = va_arg(params, int);
	ft_putchar_fd(c, 1);
	return (1);
}

static int	selector(char c, va_list params)
{
	int	a;

	a = 0;
	if (c == 'c')
		a = print_c(params);
	else if (c == 'd' || c == 'i')
		a = print_di(params);
	else if (c == 'u')
		a = print_u(params);
	else if (c == 's')
		a = print_s(params);
	else if (c == 'p')
		a = print_p(params);
	else if (c == 'x')
		a = print_x(params);
	else if (c == 'X')
		a = print_bigx(params);
	else if (c == '%')
		a = print_procent();
	else
	{
		ft_putchar_fd(c, 1);
		a = 1;
	}
	return (a);
}

static int	main_cicle(char *str, int count, va_list params)
{
	int	i;
	int	res;

	i = -1;
	while (str[++i] != 0)
	{
		if (str[i] == '%')
		{
			res = selector(str[++i], params);
			if (res < 0)
			{
				free(str);
				return (-1);
			}
			count = count + res;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
	}
	free(str);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	params;
	char	*str;
	int		count;
	int		res;

	count = 0;
	str = ft_strdup(s);
	if (!str)
		return (-1);
	va_start(params, s);
	res = main_cicle(str, count, params);
	va_end(params);
	return (res);
}
