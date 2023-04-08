# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:21:02 by orakib            #+#    #+#              #
#    Updated: 2023/04/08 04:30:27 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	
NAME = philo

SRC = ft_atoi.c garbage.c main.c monitor.c parsing.c \
		printlog.c utils.c routine.c

HEADER = philo.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re