# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:21:02 by orakib            #+#    #+#              #
#    Updated: 2023/04/08 04:22:19 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	
NAME = philo_bonus

SRC = ft_atoi_bonus.c main_bonus.c monitor_bonus.c parsing_bonus.c \
		utils_bonus.c routine_bonus.c

HEADER = philo_bonus.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -pthread #-fsanitize=thread

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