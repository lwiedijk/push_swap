# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwiedijk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/27 11:19:54 by lwiedijk      #+#    #+#                  #
#    Updated: 2021/09/01 13:14:16 by lwiedijk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADERS = push_swap.h
SRCS = create_stack.c
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
	rmdir -p $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

