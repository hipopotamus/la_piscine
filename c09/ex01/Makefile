# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 15:54:11 by sungwopa          #+#    #+#              #
#    Updated: 2021/03/11 16:17:44 by sungwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INCS = includes
TARGET = libft.a
CC = gcc
CFLAGES = -Wall -Wextra -Werror

all : $(TARGET)

.c.o:
	$(CC) $(CFLAGES) -o $(<:.c=.o) -c $< -I$(INCS)

$(TARGET) : $(OBJS)
	ar rc $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re : fclean all
