NAME = platon.a

SRCS=	srcs/structs.c \
		srcs/mini_libft.c \
		srcs/main.c \
		srcs/ft_eat.c \
		srcs/time_utils.c \
		srcs/rutine.c \
		srcs/init_mutex.c \
		srcs/printf_condition.c \
		srcs/death.c

OBJ= ${SRCS:.c=.o}

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			@ar -rc ${NAME} ${OBJ}
			${CC} $(CFLAGS) ${SRCS} -o philo

all:	${NAME}

clean:
		@echo "\n\033[32mJunk files deleted\n"
		@${RM} ${OBJS} philo.dSYM

fclean:	clean
		@${RM} ${NAME}
		@${RM} philo
		@${RM} srcs/*.o

re: fclean all

.PHONY: re fclean clean all