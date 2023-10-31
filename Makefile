# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 13:43:15 by htaheri           #+#    #+#              #
#    Updated: 2023/10/30 15:42:30 by htaheri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philosophers
CFLAGS		=		-Wall -Wextra -Werror  -g
CC			=		cc
SRCS		=		srcs/philo.c srcs/utils.c srcs/init.c srcs/routin.c srcs/print.c

LIBFT_DIR	=		libs/libft
LIBFT		=		$(LIBFT_DIR)/libft.a


all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re