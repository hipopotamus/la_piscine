C = gcc
NAME = rush-02
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
INCSDIR = includes
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INCSDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCSDIR)

clean :
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
