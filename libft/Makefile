# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lclerc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:40:47 by lclerc            #+#    #+#              #
#    Updated: 2023/03/10 16:03:50 by lclerc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 		libft.a
CC= 			CC
FLAGS=		-Wall -Wextra -Werror
CFILES=		ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_strlen.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_strlcpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_atoi.c \
					ft_strdup.c \
					ft_calloc.c \
					ft_strlcat.c \
					ft_strnstr.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_itoa.c \
					ft_split.c \
					ft_strtrim.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_printf.c \
					ft_printf_putnbr_dec_hex_ptr.c \
					ft_printf_utils.c \
					get_next_line.c \
					get_next_line_utils.c
OBJECTS=	$(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -c $(FLAGS) $(CFILES) 
	ar -rcs $(NAME) $(OBJECTS)  

clean:
	/bin/rm -f $(OBJECTS) 

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean
