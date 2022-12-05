/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleggrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:53:51 by gleggrow          #+#    #+#             */
/*   Updated: 2021/12/27 11:36:11 by gleggrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	print_c(va_list params);
int	print_di(va_list params);
int	print_u(va_list params);
int	print_s(va_list params);
int	print_p(va_list params);
int	print_x(va_list params);
int	print_bigx(va_list params);
int	print_procent(void);
int	print_x_util(char *remainder);

#endif
