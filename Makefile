SRCS =	srcs/structs.c \
		srcs/conversion_utils.c \
		srcs/main.c \
		srcs/memory_utils.c \
		srcs/ft_eat.c \
		srcs/time_utils.c \
		srcs/rutine.c \
		srcs/mutex_and_forks.c \
		srcs/philo_condition.c

OBJS = ${SRCS:.c=.o}

NAME = platon.a

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${SRCS} -o philo
			@mkdir objs
			@mv ${OBJS} objs

.PHONY: re fclean clean all

all:	${NAME}

clean:
		@echo "\n\033[32mJunk files deleted\n"
		@${RM} ${OBJS} philo.dSYM

fclean:	clean
		@${RM} ${NAME}
		@${RM} philo
		@${RM} objs

re: fclean all
