SRCS=$(wildcard srcs/*.c)
OBJ=$(SRCS:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -O3
NAME=libft.a

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

all:		$(NAME)

%.o:		%.c
			$(CC) -I. -o $@ -c $? $(CFLAGS)
clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f libft.so

re:			fclean all so

so:			$(OBJ)
			$(CC) -shared $(CFLAGS) -o libft.so $^