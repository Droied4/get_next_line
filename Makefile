# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deordone <deordone@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 13:12:44 by deordone          #+#    #+#              #
#    Updated: 2024/01/19 13:15:35 by deordone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SOURCES = \
	get_next_line.c get_next_line_utils.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c

HEADER = get_next_line_bonus.h
INCLUDE = -I

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER) Makefile
	$(AR) $(NAME) $(OBJECTS) 

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE)/$(HEADER) -c $<

clean: Makefile
	rm -f $(OBJECTS)

fclean: clean Makefile
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
