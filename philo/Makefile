COMPILER	= cc
SOURCEFILES	=	main.c	\
				init.c	\
				parsing.c	\
				philo_actions.c		\
				utils.c		\
				grim_reaper.c
NAME	= philo
OBJ		= ${SOURCEFILES:.c=.o}
RM			= rm -f
FLAGS	= -Wall -Werror -Wextra -pthread -fsanitize=thread -g

all: $(NAME)

.PHONY: all clean fclean re

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all