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
#S_FLAG	?= -fsanitize=address -g

SRC		:= \
		src/child/child_create.c \
        src/child/child_wait.c \
        src/error_handling/error_handling.c \
		src/error_handling/error_and_exit.c \
		src/initialize/initialize.c \
		src/initialize/init_in_and_outfile.c \
       	src/initialize/init_path_and_argv.c \
  		src/main.c \
  		src/pipe/pipex.c \
		src/pipe/pipe_create.c \
		src/pipe/pipes_close.c \
		src/utils/u_access_to_index.c \
		src/utils/u_execute_cmd_and_write.c \
		src/utils/u_split_path.c

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

clean:
		rm -f $(OBJ)
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