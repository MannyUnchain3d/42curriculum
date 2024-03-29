# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 19:52:44 by Manny             #+#    #+#              #
#    Updated: 2023/11/10 14:05:29 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = cub3D

# ***** BONUS MODE ***** #
BONUS = 0

# ***** COLORS ********* #
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[0;36m
BOLD	= \033[1m
ITALIC	= \033[3m
ULINE	= \033[4m
BLINK	= \033[5m
NC		= \033[0m

# ***** COMPILATION **** #
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# ***** LIBFT ********** #
LIBFT = ./libft/libft.a

# ***** MLX ************ #
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	MLX_DIR = ./minilibx-linux/
else
	MLX_DIR = ./minilibx_opengl/
endif

MLX = -L$(MLX_DIR) -lmlx
ifeq ($(OS), Linux)
	MLX += -lXext -lX11 -lm -lz
else
	MLX += -framework OpenGL -framework AppKit
endif

# ***** INCLUDES ******* #
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	INC = -I ./inc/ -I ./libft/ -I ./minilibx-linux/
else
	INC = -I ./inc/ -I ./libft/ -I ./minilibx_opengl/
endif

# ***** SOURCES ******** #
SRC_DIR = ./src/
SRC = 	error.c \
		main.c \
		exit/exit.c \
		exit/free_data.c \
		init/init_data.c \
		init/init_mlx.c \
		init/init_textures.c \
		movements/player_dir.c \
		movements/player_move.c \
		movements/player_pos.c \
		movements/player_rotate.c \
		parsing/check_args.c \
		parsing/check_map_borders.c \
		parsing/check_map_borders2.c \
		parsing/check_map.c \
		parsing/check_textures.c \
		parsing/create_map.c \
		parsing/fill_color_textures.c \
		parsing/get_file_data.c \
		parsing/parse_data.c \
		parsing/parsing_utils.c \
		rendering/images_utils.c \
		rendering/raycasting.c \
		rendering/render.c \
		rendering/textures.c

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	SRC += movements/input_handler.c
else
	SRC += movements/input_handler_mac.c
endif

SRCS = $(addprefix $(SRC_DIR), $(SRC))

# ***** OBJECTS ******** #
OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

# ***** RULES ********** #
all: $(OBJ_DIR) $(LIBFT) $(MLX) $(NAME)

 $(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/exit
	@mkdir -p $(OBJ_DIR)/init
	@mkdir -p $(OBJ_DIR)/movements
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/rendering

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(MAGENTA) $(CC) $(CFLAGS) $(INC) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(INC) -DBONUS=$(BONUS) -c $< -o $@

$(NAME): $(OBJS) $(MLX_DIR)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -DBONUS=$(BONUS) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

$(LIBFT):
	@make -sC ./libft/

$(MLX):
	@make -sC $(MLX_DIR)

bonus:
	@make -s all BONUS=1
	@echo "\n$(CYAN)(っ▀¯▀)つ $(NAME) bonus is ready!\n$(NC)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\n$(YELLOW) $(RM) $(OBJ_DIR) $(NC)"
	@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	@make fclean -sC ./libft/
	@make clean -sC $(MLX_DIR)
	@$(RM) $(NAME)
	@echo "\n$(YELLOW) $(RM) $(NAME) $(NC)"
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

# ***** MEMORY LEAKS **** #
mem1:
	valgrind --leak-check=summary ./$(NAME) maps/good.cub
mem2:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/good.cub
mem3:
	valgrind -s ./$(NAME)

.PHONY : all clean fclean re mem1 mem2 mem3
