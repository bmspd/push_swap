#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
typedef struct s_ps_list
{
	int					value;
	int					order;
	int					flag;
	int					moves;
	struct s_ps_list	*next;
	struct s_ps_list	*prev;

}	t_ps_list;

t_ps_list	*ps_lstnew(int value);
void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);
void		ps_lstadd_front(t_ps_list **lst, t_ps_list *new);
int			ps_lstsize(t_ps_list *lst);
int			int_atoi(const char *str);
int			error_message(void);
void		split_args(t_ps_list **head, int argc, char **argv);
void		check_doubles(t_ps_list *head);
void		bubble_sort(t_ps_list *head, int size);
void		push_b(t_ps_list **stack_a, t_ps_list **stack_b);
void		push_a(t_ps_list **stack_b, t_ps_list **stack_a);
void		rotate_a(t_ps_list **stack_a);
void		rotate_b(t_ps_list **stack_b);
void		reverse_rotate_a(t_ps_list **stack_a);
void		reverse_rotate_b(t_ps_list **stack_b);
void		swap_a(t_ps_list *head);
void		swap_b(t_ps_list *head);

int			take_best_case_by_value(t_ps_list *head);
void		fill_value_flags(t_ps_list *head, int best_case_order);
int			take_by_value_amount(t_ps_list *stack_a);

int			take_best_case_by_index(t_ps_list *head);
void		fill_flags(t_ps_list *head, int best_case_order);
int			take_by_index_amount(t_ps_list *stack_a);

void		make_moves(t_ps_list **stack_a, t_ps_list **stack_b,
				 int order, t_ps_list *check);

int			take_max_order(t_ps_list *head);
int			take_min_order(t_ps_list *head);
int			take_next_order(t_ps_list *stack_a,
				int current_order, t_ps_list *check);

int			calculate_moves(t_ps_list *stack_a, t_ps_list *stack_b,
				t_ps_list *head, t_ps_list *check);
void		fill_moves(t_ps_list *stack_a, t_ps_list *stack_b,
				 t_ps_list *check);
int			needed_reversions(t_ps_list *head, int order);
int			find_min_move_order(t_ps_list *head);
void		fill_stack_order(t_ps_list *stack_a, t_ps_list *check);

void		make_a_great_again(t_ps_list **stack_a);

void		make_rotations(t_ps_list **stack_a, int order);

void		two_digits(t_ps_list *stack_a);
void		three_digits(t_ps_list **stack_a);
void		four_digits(t_ps_list **stack_a, t_ps_list **stack_b);
void		five_digits(t_ps_list **stack_a, t_ps_list **stack_b);
void		more_five_digits(t_ps_list **stack_a, t_ps_list **stack_b,
				   t_ps_list *check);

int			check_zero_flag(t_ps_list *head);
void		fill_flags_best_scenario(t_ps_list *stack_a);
#endif
