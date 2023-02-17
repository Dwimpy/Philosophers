# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/02/17 18:40:21 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME			= philosophers
INCLUDE			= -I include/
DSYM			= ./philosophers.dSYM
SRC_DIR			= ./src
OBJ_DIR			= ./obj
LIBFT_FOLDER	= ./libft
LIBFT_LIB		= ./libft/libft.a
MAIN_FILE		:= main.c
NORM_INCLUDE	= ./include

# Compiler
CC			= cc
CFLAGS		= -g3 #-Wall -Werror -Wextra
LDLFLAGS	= #-lft -L ./libft/

ASAN		= #-fsanitize=address -g3
#CFLAGS		= -Ofast -march=native -flto #-fsanitize=address -g3 #-g3 -Wall -Werror -Wextra -g3 #
# FRAMEWORK	= -framework Cocoa -framework OpenGL -framework IOKit
# LDLFLAGS	= -lft -L ./libft/ -lmlx42 -L ./MLX42/  -L ./glfw-3.3.8/lib-x86_64 -lglfw3 -lm
#LDLFLAGS	= -lft -L ./libft/ -lmlx42 -L ./MLX42/ -ldl -lglfw -pthread

#Archive and Remove
RM			= rm -f
AR			= ar rcs

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources
SRCS	:=	$(wildcard $(SRC_DIR)/*.c)

# Objects
OBJS	:= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Rules
all:	$(NAME)

$(NAME): $(OBJS) $(MAIN_FILE)
	@$(CC) $(INCLUDE) $(FRAMEWORK) $(ASAN) $(OBJS) $(MAIN_FILE) -o $@ -lm $(LDLFLAGS)
	@echo "$(YELLOW)Philosophers$(DEF_COLOR) $(CYAN)done.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@ $(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

 clean:
			@$(RM) -rdf $(OBJ_DIR)
			@$(RM) -rdf $(DSYM)
			@echo "$(YELLOW)Philosophers$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)All$(DEF_COLOR) $(CYAN)objects successfully cleaned!$(DEF_COLOR)"

re:			fclean all


bonus:	libft	mlx	$(NAME)

.PHONY:		all mlx relibft libft clean fclean re norm
