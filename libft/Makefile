# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwiedijk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/30 16:06:46 by lwiedijk      #+#    #+#                  #
#    Updated: 2020/12/04 18:35:36 by lwiedijk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = 			libft.a
HEADERS = 		libft.h
OBJECTS = 		ft_atoi.o			\
	  			ft_bzero.o			\
	  			ft_calloc.o			\
	  			ft_isalnum.o		\
	  			ft_isalpha.o		\
	  			ft_isascii.o		\
	  			ft_isdigit.o		\
	  			ft_isprint.o		\
	  			ft_itoa.o			\
	  			ft_memccpy.o		\
	  			ft_memchr.o			\
	  			ft_memcmp.o			\
	  			ft_memcpy.o			\
	  			ft_memmove.o		\
	  			ft_memset.o			\
	  			ft_putchar_fd.o		\
	  			ft_putendl_fd.o		\
	  			ft_putnbr_fd.o		\
	  			ft_putstr_fd.o		\
	  			ft_split.o			\
	  			ft_strchr.o			\
	  			ft_strdup.o			\
	  			ft_strjoin.o		\
	  			ft_strlcat.o		\
	  			ft_strlcpy.o		\
	  			ft_strlen.o			\
	  			ft_strmapi.o		\
	  			ft_strncmp.o		\
	  			ft_strnstr.o		\
	  			ft_strrchr.o		\
	  			ft_strtrim.o		\
	  			ft_substr.o			\
				ft_tolower.o		\
				ft_toupper.o		\

BONUS_FILES	=	ft_lstadd_front.o	\
				ft_lstadd_back.o	\
				ft_lstclear.o		\
				ft_lstdelone.o		\
				ft_lstiter.o		\
				ft_lstlast.o		\
				ft_lstmap.o			\
				ft_lstnew.o			\
				ft_lstsize.o		\

ifdef WITH_BONUS
OBJ_FILES = $(OBJECTS) $(BONUS_FILES)
else
OBJ_FILES = $(OBJECTS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rc $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADERS)
	gcc -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJECTS) $(BONUS_FILES)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
