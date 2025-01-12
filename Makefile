
#					header

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXEC = push_swap.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(EXEC)
	$(CC) $< -o $@

$(EXEC) : $(OBJS)
	 ar -rcs $(EXEC) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJS) $(EXEC)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re