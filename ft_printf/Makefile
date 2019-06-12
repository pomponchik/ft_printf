#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:49:52 by kbethany          #+#    #+#              #
#    Updated: 2019/04/29 14:09:45 by kbethany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -g -I libft/includes/

SRC =  check_flags.c \
		first_flag_before.c \
		flag_begin_chek.c \
		flag_nuller.c \
		ft_itoa_base_long.c \
		ft_printf.c \
		is_it_flag.c \
		just_to_print_len.c \
		obertka.c \
		ok.c \
		only_1_flag.c \
		out_from_flag.c \
		out_str.c \
		post_persent.c \
		print_flag_d.c \
		print_flag_f.c \
		print_flag_o.c \
		print_flag_p.c \
		print_flag_sc.c \
		print_flag_u.c \
		print_flag_x.c \
		second_flag.c \
		size_flag.c \
		printer.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

LIBFTOBJ = libft/*.o

all: $(NAME)

$(OBJ): $(SRC)
	@make -C libft
	@gcc -c $(SRC) $(CFLAGS)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)
	@ranlib $(NAME)

clean:
	@rm -r $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
