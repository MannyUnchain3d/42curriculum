# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 13:33:09 by Manny             #+#    #+#              #
#    Updated: 2023/07/07 00:54:39 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = -rm -rf

SRC_DIR = src
SRC = pipex.c utils.c
SRC_B = pipex_bonus.c utils.c utils_bonus.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(SRC_DIR)/$(OBJ_DIR)/%.o)
OBJ_B = $(SRC_B:%.c=$(SRC_DIR)/$(OBJ_DIR)/%.o)

HEADER = -I inc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
lIBFTFLAGS = -L$(LIBFT_DIR) -lft

$(SRC_DIR)/$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(SRC_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(lIBFTFLAGS) -o $(NAME)
	@echo "\n\e[32m---- (っ▀¯▀)つ $(NAME) is compiled! ----\e[0m\n"

bonus: $(LIBFT) $(OBJ) $(OBJ_B)
	$(CC) $(OBJ_B) $(lIBFTFLAGS) -o $(NAME)
	@echo "\n\e[32m---- (っ▀¯▀)つ $(NAME) bonus is compiled! ----\e[0m\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(SRC_DIR)/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@echo "\n\e[31m---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----\e[0m\n"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus 