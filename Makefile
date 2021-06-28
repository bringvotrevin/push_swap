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
		push_swap.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		sort.c \
		sort_a_to_b.c \
		sort_b_to_a.c \
		save_num.c \
		free.c \
		util_sort.c \
		util_check.c \
		util_lst.c \

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
