# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:18:50 by lclerc            #+#    #+#              #
#    Updated: 2023/03/21 13:31:40 by lclerc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
# $@ and $^ are special variables that represent the target and the first
# dependency:
# - $@ represents the target, the file being built.
# - $< represents thhe first dependency, the file required to build the target.
# 
#******************************************************************************#

BINARY_1 = server
BINARY_2 = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I./minitalk_common.h
COMPILE = $(CC) $(CFLAGS)
SRCS = client.c server.c
OBJ = $(SRCS:%.c=%.o)

#******************************************************************************#

all: $(BINARY_1) $(BINARY_2)

$(BINARY_1): server.o libft/libft.a
	$(COMPILE) $^ -o $@

$(BINARY_2): client.o libft/libft.a
	$(COMPILE) $^ -o $@

%.o: %.c
	$(COMPILE) $< -I libft -c -o $@

libft/libft.a:
	$(MAKE) -C libft

#******************************************************************************#

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	/bin/rm -f $(BINARY_1) $(BINARY_2)
	$(MAKE) -C libft fclean

re: fclean all

#******************************************************************************#
.PHONY: all clean fclean re 
#******************************************************************************#
