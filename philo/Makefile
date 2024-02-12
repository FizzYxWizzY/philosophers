# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 15:53:34 by mflury            #+#    #+#              #
#    Updated: 2024/02/12 02:53:22 by mflury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

SRC_PATH = src/

SRC = 	main.c \
		thread.c \
		init_utils.c \
		utils1.c \
		utils2.c \
		utils3.c \

SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME 	= philo
AR 		= ar rcs
CC		= @gcc
RM		= rm -f

INCLUDES = -I includes/

CFLAGS = -g -pthread -Werror -Wextra -Wall #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
		@$(ECHO) "$(YELLOW)Compiling philosopher...$(RESETTXT)"
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) 
		@$(ECHO) "$(GREEN)$(BOLD)Done !!!$(RESETTXT)"

%.o:$(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@
		$(PRINT) "$(YELLOW)Creating objets files $@ $(RESETTXT)\n"

clean:
		$(ECHO) "$(RED)Deleting objets files$(RESETTXT)"
		@$(RM) $(OBJS)

fclean:	clean
		$(ECHO) "$(RED)Deleting others files$(RESETTXT)"
		@$(RM) $(NAME)
		
re:		fclean all

.PHONY: all clean fclean re 