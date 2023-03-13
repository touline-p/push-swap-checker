# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpoumeau <bpoumeau@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 03:31:03 by bpoumeau          #+#    #+#              #
#    Updated: 2023/02/17 14:16:29 by bpoumeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC := cc

FILES = basic_algo.c \
	magical_inserting.c \
	checking_sort.c \
	init_sorting_tools.c \
	instructions.c \
	opti_str.c \
	parsing_args.c \
	main.c \
	t_tabs_utils.c \
	utils.c \
	magic_sort.c \
	execute_ind.c \
	sort_three.c \
	bring_back_to_sorted.c \
	mi_index_utils.c \
	build_ind.c \
	instr_p_n_s.c \
	instr_r_n_rr.c \
	writing_instructions_pns.c \
	writing_instructions_rotates.c \
	rotate_to_min.c \

CH_FILES := ch_main.c \
	init_sorting_tools.c \
	instr_p_n_s.c \
	instr_r_n_rr.c \
	instr_both.c \
	parsing_args.c \
	t_tabs_utils.c \
	read_n_exec.c \

FLAGS := -Wall -Wextra -Werror -g3

HEADER := push_swap.h

HLIB :=	libft/libft.h \

SRC := $(FILES) \

OBJ := $(addprefix obj/, $(FILES:.c=.o)) \

CHOBJ := $(addprefix obj/, $(CH_FILES:.c=.o)) \

LIBS = libft/libft.a
LIB_FLAGS := -Llibft -lft

all:	CHECKLIB
	$(MAKE) $(NAME)
	$(MAKE) $(CHECKER)

bonus:
	-rm obj/main.o
	make MAIN=main_bonus.c

CHECKLIB:
	make -C libft

OTHER_DEL:
	-rm $(OTHER)

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(FLAGS) $(LIB_FLAGS) $(OBJ) -o $(NAME) $(LIBS)

$(CHECKER): $(LIBS) $(CHOBJ)
	$(CC) $(FLAGS) $(LIB_FLAGS) $(CHOBJ) -o $(CHECKER) $(LIBS)

obj/%.o: srcs/%.c $(HEADER) $(HLIB)
	@mkdir -p ${shell dirname $@}
	$(CC) $(FLAGS) -c $< -o $@ -I libft -I.

obj/%.o: ch_src/%.c $(HEADER) $(HLIB)
	@mkdir -p ${shell dirname $@}
	$(CC) $(FLAGS) -c $< -o $@ -I libft -I.

$(ODIR):
	mkdir $(ODIR)

clean:
	rm -rf obj/
	make fclean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

normy:
	norminette $(SRC) $(HEADER)

cleanm:
	clear
	make

ctest:
	clear
	make 
	./push_swap

.PHONY: all clean fclean re libclean normy

