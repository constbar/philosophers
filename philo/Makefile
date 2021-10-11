NAME = philo

SRC = philo.c utils.c init.c actions.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

$(NAME): $(OBJ)
	${RM} philo
	@gcc -g -Wall -Wextra -Werror -pthread -o $(NAME) $(OBJ) -fsanitize=address

all: $(NAME)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
