# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/02/28 17:36:12 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME			= philo
INCLUDE			= -I include/
DSYM			= ./philo.dSYM
SRC_DIR			= ./src
OBJ_DIR			= ./obj
MAIN_FILE		:= main.c
NORM_INCLUDE	= ./include

# Compiler
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g3 -pthread

ASAN		= #-fsanitize=address

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
SRCS	:=	memory_manager.c parse_printing.c parsing_checker.c philo_actions.c  \
			philo_forks.c philo_monitor.c philo_printing.c philo_process.c  \
			philo_timing.c process_manager.c semaphore_manager.c state_initializers.c  \
			state_rules.c utility_functions.c utility_functions2.c
# Objects
OBJS	:= 	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Rules
all:	$(NAME)

$(NAME): $(OBJS) $(MAIN_FILE)
	@$(CC) $(INCLUDE) $(FRAMEWORK) $(ASAN) $(OBJS) $(MAIN_FILE) -o $@ $(LDLFLAGS)
	@echo "$(YELLOW)Philosophers$(DEF_COLOR) $(CYAN)done.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@ $(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@ 

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
