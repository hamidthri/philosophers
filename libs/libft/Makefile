# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 16:04:04 by htaheri           #+#    #+#              #
#    Updated: 2023/07/24 14:38:07 by htaheri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_strlcpy.c ft_strlen.c ft_memmove.c ft_memcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
 ft_memset.c ft_bzero.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_atoi.c ft_itoa.c ft_strncmp.c\
 ft_strnstr.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c\
 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS_SRC = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRC:.c=.o)

NAME = libft.a
all: $(NAME)
$(NAME): $(OBJS_SRC)
	ar rcs $(NAME) $(OBJS_SRC)

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJS_SRC) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
