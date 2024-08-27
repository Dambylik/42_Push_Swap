# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okapshai <okapshai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 13:45:19 by okapshai          #+#    #+#              #
#    Updated: 2024/08/18 12:56:11 by okapshai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap

SRCS =	error_handling.c ft_atoi_ps.c\
		exec_actions1.c exec_actions2.c stack_sort.c\
		stack_sort_utils.c\
		stack_utils.c stack_utils2.c\
		transfer_to_a.c transfer_to_a2.c\
		ft_split_ps.c main.c

HDRS =	push_swap.h

OBJS = 	$(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I./includes -I$(LIBFT_DIR)

CC = 	cc
CFLAGS = -Wall -Wextra -Werror
RM = 	rm -f

GREEN = '\033[0;32m'
CYAN = '\033[0;36m'
WHITE = '\033[0;37m'

all:	$(LIBFT) $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LIBFT)
		@echo ✅ $(GREEN)"Project successfully compiled"

$(LIBFT):
	@echo ⏳ $(GREEN)"Compilation in progress"$(WHITE)
	@make -C $(LIBFT_DIR)
	
clean:
	@echo 🧹 $(CYAN)"Removing .o files"$(WHITE)
	${RM} ${OBJS}
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@echo 🧹 $(CYAN)"Removing all"$(WHITE)
	${RM} ${NAME}
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re