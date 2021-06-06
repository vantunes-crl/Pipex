NAME = pipex

FLAGS = -Wall -Werror -Wextra

SRCS = pipex.c utils.c path_finder.c ft_split.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	gcc $(OBJS) -g -o $(NAME)

all: $(NAME) clean

clean:
	rm $(OBJS)

fclean:
	rm $(NAME) $(OBJS)