# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-bus <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/04 15:34:16 by lvan-bus      #+#    #+#                  #
#    Updated: 2022/10/19 13:03:17 by lvan-bus      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=======================================#
#========		VARIABLES:		========#
#=======================================#

NAME 		:= libft.a
CC			:= cc
CFLAGS 		?= -Wall -Wextra -Werror
IFLAG		?= -I.
#LDFLAGS	?= -fsanitize=address -g

SRC_LIBFT	:= \
	array/ft_array_len.c \
	array/ft_array_print.c \
	ascii/ft_isalnum.c \
	ascii/ft_isalpha.c \
	ascii/ft_isascii.c \
	ascii/ft_isdigit.c \
	ascii/ft_isprint.c \
	convert/ft_atoi.c \
	convert/ft_atoi_with_overflow.c \
	convert/ft_itoa.c \
	convert/ft_tolower.c \
	convert/ft_toupper.c \
	convert/ft_str_tolower.c \
	error_handling/error_double_check.c \
	error_handling/error_limit_check.c \
	error_handling/error_num_check.c \
	error_handling/error_num_check_for_2d_array.c \
	lists/add_back.c \
	lists/find_list_lowest.c \
	lists/list_last.c \
	lists/list_reversed_sorted.c \
	lists/list_size.c \
	lists/list_sorted.c \
	lists/new_list.c \
	lists/node_count.c \
	mem/ft_bzero.c \
	mem/ft_calloc.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	put/ft_putchar_fd.c \
	put/ft_putendl_fd.c \
	put/ft_putnbr_fd.c \
	put/ft_putstr_fd.c \
	str/ft_split.c \
	str/ft_strchr.c \
	str/ft_strdup.c \
	str/ft_striteri.c \
	str/ft_strjoin.c \
	str/ft_strlcat.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c \
	str/ft_strmapi.c \
	str/ft_strncmp.c \
	str/ft_strnstr.c \
	str/ft_strrchr.c \
	str/ft_strtrim.c \
	str/ft_substr.c

SRC_GNL	:= \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/gnl_print_fd.c

SRC_PF	:= \
	ft_printf/ft_printf.c \
	ft_printf/ft_itoa.c \
	ft_printf/ft_puts.c \
	ft_printf/ft_str.c \
	ft_printf/ft_memcpy.c \
	ft_printf/ft_hex.c

OBJ			:= $(SRC_LIBFT:.c=.o) $(SRC_GNL:.c=.o) $(SRC_PF:.c=.o)

#=======================================#
#========		RECIPES:		========#
#=======================================#

all: $(NAME)

$(NAME): $(OBJ)
		ar -cr $(NAME) $(OBJ)

%.o: %.c
		$(CC) -c $(CFLAGS) $(IFLAG) -o $@ $^

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
