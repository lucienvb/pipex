# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-bus <lvan-bus@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/12 16:36:24 by lvan-bus      #+#    #+#                  #
#    Updated: 2023/01/17 16:54:19 by lvan-bus      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME	:= pipex
CC		:= cc
C_FLAGS	?= -Wall -Wextra -Werror
I_FLAG	?= -I.
# --> system("leaks executable") doesn't work with fsanitize on! <--
S_FLAG	?= -fsanitize=address -g

SRC_REG		:= \
		src/child/child_execute.c \
		src/child/child_create.c \
        src/child/child_wait.c \
        src/error_handling/error_handling_one_pipe.c \
		src/error_handling/error_message.c \
		src/error_handling/message_wrong_input.c \
		src/initialize/initialize.c \
		src/initialize/init_in_and_outfile.c \
       	src/initialize/init_path_and_argv.c \
       	src/main.c \
  		src/pipe/pipex.c \
		src/pipe/pipe_create.c \
		src/utils/u_access_to_index.c \
		src/utils/u_execute_parent.c \
		src/utils/u_split_path.c

SRC_BONUS	:= \
		src/child/child_execute.c \
		src/child/child_create.c \
        src/child/child_wait.c \
        src/error_handling/error_handling_one_pipe.c \
		src/error_handling/error_message.c \
		src/error_handling/message_wrong_input.c \
		src/initialize/initialize.c \
		src/initialize/init_in_and_outfile.c \
       	src/initialize/init_path_and_argv.c \
  		src/pipe/pipex.c \
		src/pipe/pipe_create.c \
		src/utils/u_access_to_index.c \
		src/utils/u_execute_parent.c \
		src/utils/u_split_path.c \
		src/bonus/error_handling_bonus.c \
		src/bonus/here_doc_bonus.c \
		src/bonus/init_here_doc_bonus.c \
		src/bonus/initialize_bonus.c \
		src/bonus/main_bonus.c

ifdef WITH_BONUS
SRC = $(SRC_BONUS)
else
SRC = $(SRC_REG)
endif

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(CC) $(I_FLAG) $(S_FLAG) $^ ./libft/libft.a -o $(NAME)

%.o: %.c
		$(CC) -c $(C_FLAGS) $(I_FLAG) -o $@ $^

bonus:
		$(MAKE) WITH_BONUS=1 all

clean:
		rm -f $(SRC_REG:.c=.o)
		rm -f $(SRC_BONUS:.c=.o)
		$(MAKE) -C ./libft clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean

comp: all clean

re: fclean all

#=======================================#
#========	  UNIT TESTING		========#
#=======================================#

LIST_TEST := \
		src/error_handling/p_input_parsing.c

test: $(OBJ)
		$(CC) $(C_FLAGS) UnityExample.c $(LIST_TEST) unity/libunity.a ./libft/libft.a -o unittest
		@ ./unittest

.PHONY: all clean fclean re