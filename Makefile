# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwiedijk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/27 11:19:54 by lwiedijk      #+#    #+#                  #
#    Updated: 2021/10/19 14:55:12 by lwiedijk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADERS = push_swap.h
SRCS =	create_stack.c a_instructions.c \
		b_instructions.c nodes.c \
		sort_small_stack.c check_input.c \
		free.c sort_large_stack.c \
		simplify_stack_input.c sort_stack.c \

OBJS_DIR = objs/
_OBJS = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(_OBJS))

LIBFT_DIR = libft/
LIBFT = libft.a

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) ./
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L. -lft -o $(NAME)

$(OBJS_DIR)%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBFT) $(_OBJS) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
