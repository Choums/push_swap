SRCS		=	srcs/push_swap.c\
				srcs/push_swap_utils.c\
				srcs/stack_management.c\
				srcs/another_stack_management.c\
				srcs/algo.c\
				srcs/another_algo.c

OBJS		=	${SRCS:.c=.o}

NAME		=	push_swap

LIB			=	./libft/libft.a

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM			=	rm -f

${NAME}:		${OBJS}
				${MAKE} -C ./libft
				${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}
				${MAKE} clean -C ./libft


fclean:			clean
				${RM} ${NAME}
				${MAKE} fclean -C ./libft

re:				fclean all

.PHONY:			all clean fclean re
