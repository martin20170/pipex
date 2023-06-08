SRCS = main.c

NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARRC = ar rcs



${NAME}:	${SRCS}
				make all -C ./libft
				${CC} ${CFLAGS} ${SRCS} libft/libft.a -o ${NAME}



all:	${NAME}


clean:
				make clean -C ./libft

fclean:	clean
				rm -f ${NAME}
				make fclean -C ./libft

re: fclean all

.PHONY : all clean fclean re
