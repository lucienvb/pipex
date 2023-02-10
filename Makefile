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
CFLAGS	?= -Wall -Wextra -Werror
#LDFLAGS	?= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o3 -march=native
IFLAG	?= -I.
SFLAG	?= -fsanitize=address -g

SRC		:= \
		src/main.c \
		src/error_handling/perror_and_exit.c \
		src/error_handling/p_input_parsing.c \
		src/pipex/pipex.c \
		src/pipex/child_functions/create_child.c \
		src/pipex/child_functions/wait_for_child.c \
		src/pipex/pipe_functions/create_pipe.c \
		src/pipex/pipe_functions/close_pipes.c

OBJ		:= $(SRC:.c=.o)

#=======================================#
#========		RECIPIES		========#
#=======================================#

all:	$(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(CC) $(LDFLAGS) $(IFLAG) $(SFLAG) $^ ./libft/libft.a -o $(NAME)

%.o: %.c
		$(CC) -c $(CFLAGS) $(IFLAG) -o $@ $^

clean:
		rm -f $(OBJ)
		$(MAKE) -C ./libft clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean

re: fclean all

#=======================================#
#========	  UNIT TESTING		========#
#=======================================#

#LIST_TEST :=

test: $(OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) UnityExample.c $(LIST_TEST) unity/libunity.a ./libft/libft.a -o unittest
		@ ./unittest

.PHONY: all clean fclean re