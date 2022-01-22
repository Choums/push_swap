SRCS	=	push_swap.c

OBJS	=	${SRCS=.c.o}


CC		=	clang

CFLAGS	=	-Wextra -Werror	-W

.c.o:		${CC} ${CFLAGS}

RM		=	rm -f

all:

clean:

fclean:

re:			

.PHONY:		all clean fclean re