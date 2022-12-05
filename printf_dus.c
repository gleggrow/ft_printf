/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleggrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:59:23 by gleggrow          #+#    #+#             */
/*   Updated: 2022/01/04 23:11:30 by hovalygta        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	print_di(va_list params)
{
	int		d;
	char	*str;
	int		num;

	d = va_arg(params, int);
	str = ft_itoa(d);
	if (!str)
		return (-1);
	num = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (num);
}

int	print_u(va_list params)
{
	unsigned int	u;
	char			*str;
	int				num;

	u = va_arg(params, unsigned int);
	str = ft_uitoa(u);
	if (!str)
		return (-1);
	num = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (num);
}

int	print_s(va_list params)
{
	char	*s;
	int		nums;

	nums = 0;
	s = va_arg(params, char *);
	ft_putstr_fd(s, 1);
	if (s)
		nums = ft_strlen(s);
	else
	{
		ft_putstr_fd("(null)", 1);
		nums = 6;
	}
	return (nums);
}

int	print_procent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
