/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleggrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:00:06 by gleggrow          #+#    #+#             */
/*   Updated: 2021/12/27 11:00:38 by gleggrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convert_16(unsigned int c)
{
	char	*res;

	res = NULL;
	if (c <= 9)
		res = ft_uitoa(c);
	else if (c == 10)
		res = ft_strdup("a");
	else if (c == 11)
		res = ft_strdup("b");
	else if (c == 12)
		res = ft_strdup("c");
	else if (c == 13)
		res = ft_strdup("d");
	else if (c == 14)
		res = ft_strdup("e");
	else if (c == 15)
		res = ft_strdup("f");
	return (res);
}

char	*convert_big16(unsigned int c)
{
	char	*res;

	res = NULL;
	if (c <= 9)
		res = ft_uitoa(c);
	else if (c == 10)
		res = ft_strdup("A");
	else if (c == 11)
		res = ft_strdup("B");
	else if (c == 12)
		res = ft_strdup("C");
	else if (c == 13)
		res = ft_strdup("D");
	else if (c == 14)
		res = ft_strdup("E");
	else if (c == 15)
		res = ft_strdup("F");
	return (res);
}

int	print_p(va_list params)
{
	char				*str;
	char				*remainder;
	char				*tmp;
	unsigned long int	x;

	remainder = NULL;
	x = va_arg(params, unsigned long int);
	if (x == 0)
		remainder = ft_strdup("0");
	while (x > 0)
	{
		str = convert_16(x % 16);
		if (!str)
			return (-1);
		tmp = remainder;
		remainder = ft_strjoin(remainder, str);
		free(tmp);
		free(str);
		x = x / 16;
	}
	ft_putstr_fd("0x", 1);
	return (print_x_util(remainder) + 2);
}

int	print_x(va_list params)
{
	unsigned int	x;
	char			*str;
	char			*remainder;
	char			*tmp;

	remainder = NULL;
	x = va_arg(params, unsigned int);
	if (x == 0)
		remainder = ft_strdup("0");
	while (x > 0)
	{
		str = convert_16(x % 16);
		if (!str)
			return (-1);
		tmp = remainder;
		remainder = ft_strjoin(remainder, str);
		free(tmp);
		free(str);
		x = x / 16;
	}
	return (print_x_util(remainder));
}

int	print_bigx(va_list params)
{
	unsigned int	x;
	char			*str;
	char			*remainder;
	char			*tmp;

	remainder = NULL;
	x = va_arg(params, unsigned int);
	if (x == 0)
		remainder = ft_strdup("0");
	while (x > 0)
	{
		str = convert_big16(x % 16);
		if (!str)
			return (-1);
		tmp = remainder;
		remainder = ft_strjoin(remainder, str);
		free(tmp);
		free(str);
		x = x / 16;
	}
	return (print_x_util(remainder));
}
