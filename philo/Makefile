SRCS =	srcs/basic_utils.c \
		srcs/conversion_utils.c \
		srcs/main.c \
		srcs/memory_utils.c \
		srcs/test_utils.c

OBJS = ${SRCS:.c=.o}

NAME = platon.a

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${SRCS} -o philo

.PHONY: re fclean clean all

all:	${NAME}

clean:
		@echo "\n\033[32mJunk files deleted\n"
		@${RM} ${OBJS}
		@${RM} objs

fclean:	clean
		@${RM} ${NAME}
		@${RM} philo

re: fclean all
