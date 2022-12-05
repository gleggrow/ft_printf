# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleggrow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 10:54:54 by gleggrow          #+#    #+#              #
#    Updated: 2022/01/05 01:37:14 by hovalygta        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c printf_dus.c printf_pxx.c

OBJS = ft_printf.o printf_dus.o printf_pxx.o

HEADERS = libftprintf.h libft/libft.h

OBJS_TMP = ft_atoi.o ft_bzero.o ft_memcpy.o ft_memset.o \
ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
ft_split.o ft_memccpy.o ft_memchr.o ft_putchar_fd.o \
ft_itoa.o ft_memcmp.o ft_putnbr_fd.o ft_putstr_fd.o \
ft_strchr.o ft_strdup.o ft_strlen.o ft_putendl_fd.o \
ft_strlcpy.o ft_strjoin.o ft_strmapi.o ft_strncmp.o \
ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_strlcat.o \
ft_tolower.o ft_toupper.o ft_memmove.o ft_substr.o \
ft_calloc.o ft_isalnum.o ft_uitoa.o

OBJS_LIBFT = $(addprefix libft/,$(OBJS_TMP))


FLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	ar rc $(NAME) $(OBJS) $(OBJS_LIBFT)
%.o: %.c
	cc -c $(FLAGS) $< -I $(HEADERS)
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
re: fclean all
