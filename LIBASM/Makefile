# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 20:50:12 by evila-ro          #+#    #+#              #
#    Updated: 2020/12/17 22:31:22 by evila-ro         ###   ########.fr        #
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


fclean:		clean
	rm $(NAME)

re:			fclean all


.SILENT:	all $(NAME) main .s.o
.PHONY:		all run fclean clean
