# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efumiko <efumiko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 14:31:46 by efumiko           #+#    #+#              #
#    Updated: 2020/10/21 14:52:58 by efumiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NASM_COMP = nasm -felf64

SRC =	ft_strlen.s ft_strcmp.s \
		ft_read.s ft_write.s \
		ft_strdup.s ft_strcpy.s
OBJ = $(SRC:.s=.o);

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $?
	ranlib $(NAME)

%.o: %.s
	$(NASM_COMP) $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re