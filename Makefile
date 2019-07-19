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

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O3

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = -I include -I libft/includes

SOURCES = check_flags.c first_flag_before.c flag_begin_chek.c \
flag_nuller.c ft_itoa_base_long.c ft_printf.c is_it_flag.c \
just_to_print_len.c ok.c only_1_flag.c out_from_flag.c out_str.c \
post_persent.c print_flag_d.c print_flag_f.c print_flag_o.c \
print_flag_p.c print_flag_sc.c print_flag_u.c print_flag_x.c \
second_flag.c size_flag.c printer.c ft_itoa_specific.c \
ft_itoa_specific_part_1.c ft_itoa_specific_part_2.c fixer_free.c \
fixer_num.c fixer_p.c fixer_str.c fixer.c charer.c print_lst.c \
print_flag_bonus.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
