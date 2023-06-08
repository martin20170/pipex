SRCS = get_next_line.c get_next_line_utils.c

OBJDIR = ../objs

OBJS = ${addprefix ${OBJDIR}/,${SRCS:.c=.o}}

ESSENTIALSSRCS = ../essentials/ft_calloc.c ../essentials/ft_isdigit.c ../essentials/ft_memcmp.c ../essentials/ft_putchar_fd.c ../essentials/ft_split.c ../essentials/ft_strjoin.c ../essentials/ft_strmapi.c ../essentials/ft_strtrim.c \
../essentials/ft_atoi.c ../essentials/ft_isalnum.c ../essentials/ft_isprint.c ../essentials/ft_memcpy.c ../essentials/ft_putendl_fd.c ../essentials/ft_strchr.c ../essentials/ft_strlcat.c ../essentials/ft_strncmp.c ../essentials/ft_substr.c \
../essentials/ft_isalpha.c ../essentials/ft_itoa.c ../essentials/ft_memmove.c ../essentials/ft_putnbr_fd.c ../essentials/ft_strdup.c ../essentials/ft_strlcpy.c ../essentials/ft_strnstr.c ../essentials/ft_tolower.c ../essentials/ft_bzero.c \
../essentials/ft_isascii.c ../essentials/ft_memchr.c ../essentials/ft_memset.c ../essentials/ft_putstr_fd.c ../essentials/ft_striteri.c ../essentials/ft_strlen.c ../essentials/ft_strrchr.c ../essentials/ft_toupper.c \
../essentials/ft_lstnew.c ../essentials/ft_lstadd_front.c ../essentials/ft_lstsize.c ../essentials/ft_lstlast.c ../essentials/ft_lstadd_back.c \
../essentials/ft_lstdelone.c ../essentials/ft_lstclear.c ../essentials/ft_lstiter.c ../essentials/ft_lstmap.c

NAME = get_next_line.a

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADERS = .

ARRC = ar rcs

${OBJDIR}/%.o : %.c	${ESSENTIALSSRCS}
				mkdir -p ${OBJDIR}
				${GCC} ${CFLAGS} -c $< -o $@ -I .


${NAME}:		${OBJS}

all:	${NAME}


clean:
				rm -rf ${OBJDIR}
				make clean -C ../essentials

fclean:	clean
				rm -f ${NAME}
				make fclean -C ../essentials

re: fclean all

.PHONY : all clean fclean re
