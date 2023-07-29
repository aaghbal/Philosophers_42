# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 15:27:36 by aaghbal           #+#    #+#              #
#    Updated: 2023/07/24 09:25:32 by aaghbal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
HEADER = philo.h
SRC = philo.c utils.c parsing.c routine.c initialisation.c create.c \
		check_death.c
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