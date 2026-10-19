NAME=libft.a
COMPILER=cc
FLAGS=-Wall -Wextra -Werror
SOURCES=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
OBJS=$(SOURCES:%.c=%.o)
HEADERS=

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS):%.o:%.c
	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all