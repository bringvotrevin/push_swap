.PHONY : bonus all claen fclean re
NAME = push_swap
HEADER = includes
SRCDIR = srcs/
LIB = lib/
CC = gcc
RM = rm -rf
WFLAGS = -Wall -Werror -Wextra
INCFLAGS = -I$(HEADER)
DEBUGFLAGS = -g -fsanitize=address
CFLAGS = $(WFLAGS) $(INCFLAGS) $(DEBUGFLAGS)
LIBFLAGS = -L $(LIB)libft -lft
FILES = parse.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		util_lst.c \
		free.c \
		three_input.c \
		five_input.c \
		check_util.c \
		util.c \
		stack.c \
		save_num.c

SRCS =	$(addprefix $(SRCDIR), $(FILES))

OBJS = $(SRCS:.c=.o)

${NAME} :	${OBJS}
			make -C $(LIB)libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

all :		${NAME}

clean :     
			make clean -C $(LIB)libft
			${RM} ${OBJS}

fclean :	clean
			make fclean -C $(LIB)libft
			${RM} ${NAME}

re :		fclean all
