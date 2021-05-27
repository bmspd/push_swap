SRCS			= main.c ps_lstnew.c ps_lstadd_back.c ps_lstsize.c int_atoi.c \
					errors.c split_arguments.c check_doubles.c bubble_sort.c \
					ps_commands1.c ps_lstadd_front.c ps_commands2.c by_value.c \
					by_index.c rotations.c calculations.c orders.c \
					stack_a_movement.c diff_amount_behaviour.c
DIR_S			= src
SOURCE			=$(addprefix $(DIR_S)/,$(SRCS))
OBJS			= $(SOURCE:.c=.o)
HEADER			= ./includes/push_swap.h
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I $(HEADER)

NAME			= push_swap

all:			$(NAME)

%.o:		%.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
				make -C ./libft/
				$(CC) -o $(NAME )$@ $^ -Llibft -lft

clean:
				$(RM) $(OBJS)
				make -C ./libft/ clean

fclean:			clean
				$(RM) $(NAME)
				make -C ./libft/ fclean

re:				fclean all

.PHONY:			all clean fclean re