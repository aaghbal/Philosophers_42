# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 15:43:48 by aaghbal           #+#    #+#              #
#    Updated: 2023/07/24 09:26:57 by aaghbal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
HEADER = philo_bonus.h
SRC = philo_bonus.c utils_bonus.c parsing_bonus.c routine_bonus.c init_bonus.c \
	create_bonus.c
OBJ_SRC = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_SRC) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

%.o  : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJ_SRC)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean re 