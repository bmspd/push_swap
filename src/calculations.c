#include "../includes/push_swap.h"

int	calculate_moves(t_ps_list *stack_a, t_ps_list *stack_b,
					t_ps_list *head, t_ps_list *check)
{
	int	stack_b_moves;

	if (ps_lstsize(stack_b) - ps_lstsize(head) > ps_lstsize(stack_b) / 2)
		stack_b_moves = ps_lstsize(head);
	else
		stack_b_moves = ps_lstsize(stack_b) - ps_lstsize(head);
	if (head->order > take_max_order(stack_a))
	{
		stack_b_moves = stack_b_moves
			+ needed_reversions(stack_a, take_max_order(stack_a)) + 1;
	}
	else if (head->order < take_min_order(stack_a))
	{
		stack_b_moves = stack_b_moves
			+ needed_reversions(stack_a, take_min_order(stack_a));
	}
	else
	{
		stack_b_moves = stack_b_moves + needed_reversions(stack_a,
				take_next_order(stack_a, head->order, check));
	}
	stack_b_moves++;
	return (stack_b_moves);
}

void	fill_moves(t_ps_list *stack_a, t_ps_list *stack_b, t_ps_list *check)
{
	t_ps_list	*tmp;

	tmp = stack_b;
	while (tmp)
	{
		tmp->moves = calculate_moves(stack_a, stack_b, tmp, check);
		tmp = tmp->next;
	}
}

int	needed_reversions(t_ps_list *head, int order)
{
	t_ps_list	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->order == order)
			break ;
		tmp = tmp->next;
	}
	if (ps_lstsize(head) - ps_lstsize(tmp) > ps_lstsize(head) / 2)
		return (ps_lstsize(tmp));
	else
		return (ps_lstsize(head) - ps_lstsize(tmp));
}
