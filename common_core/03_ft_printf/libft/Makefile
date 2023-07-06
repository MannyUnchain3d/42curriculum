# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 19:14:30 by Manny             #+#    #+#              #
#    Updated: 2023/07/07 00:55:32 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar
ARFLAGS = rcs
RM = rm -rf

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c\
		ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c ft_putstr.c\
		ft_isspace.c
SRC_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B = $(SRC_B:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) is compiled! ----\033[0m\n"

bonus: $(OBJ_DIR) $(OBJ) $(OBJ_B)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_B)
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) bonus is compiled! ----\033[0m\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----\033[0m\n"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus