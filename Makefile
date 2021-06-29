.PHONY : bonus all claen fclean re
NAME = push_swap
BONUS_NAME = checker
HEADER = includes
SRCDIR = srcs/
LIB = lib/
CC = gcc
RM = rm -rf
WFLAGS = -Wall -Werror -Wextra
INCFLAGS = -I$(HEADER)
DEBUGFLAGS = -g
CFLAGS = $(WFLAGS) $(INCFLAGS) $(DEBUGFLAGS)
LIBFLAGS = -L $(LIB)libft -lft
FILES = main.c \
		parse.c \
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
		util_lst.c

BONUS_FILES = checker_bonus.c \
			parse.c \
			push.c \
			swap.c \
			rotate.c \
			reverse_rotate.c \
			free.c \
			util_check.c \
			util_lst.c

SRCS =	$(addprefix $(SRCDIR), $(FILES))

BN_SRCS = $(addprefix $(SRCDIR), $(BONUS_FILES))

OBJS = $(SRCS:.c=.o)

BN_OBJS = $(BN_SRCS:.c=.o)

${NAME} :	${OBJS}
			make -C $(LIB)libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

${BONUS_NAME} : ${BN_OBJS}
				$(CC) $(CFLAGS) $(BN_OBJS) $(LIBFLAGS) -o $(BONUS_NAME)

all :		${NAME}

clean :     
			make clean -C $(LIB)libft
			${RM} ${OBJS} ${BN_OBJS}

fclean :	clean
			make fclean -C $(LIB)libft
			${RM} ${NAME} ${BONUS_NAME}

bonus : all ${BONUS_NAME}

re :		fclean all
