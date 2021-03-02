# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 20:50:12 by evila-ro          #+#    #+#              #
#    Updated: 2021/02/28 21:45:23 by evila-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRC		=	ft_strlen.s	\
			ft_strcpy.s	\
			ft_strcmp.s	\
			ft_write.s	\
			ft_read.s	\
			ft_strdup.s

AFLAGS	= -fmacho64

OBJ		= $(SRC:.s=.o)

.s.o:
	nasm $(AFLAGS) $^

all:		$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)

main:		$(NAME)
	gcc main.c $(NAME) -o main

run:		main
	./main

clean:
	rm $(OBJ)
	rm main

fclean:		clean
	rm $(NAME)
	rm main

re:			fclean all main


.SILENT:	all $(NAME) main .s.o
.PHONY:		all run fclean clean
