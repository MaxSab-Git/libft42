NAME=libft.a
COMPILER=cc
FLAGS=-Wall -Wextra -Werror
SOURCES=ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c

TESTSOURCES=main.c

OBJS=$(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS):%.o:%.c
	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re test

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	norminette --use-gitignore
	$(COMPILER) $(TESTSOURCES) -I./ -L./ -lft -lbsd
	./a.out