#include "../includes/push_swap.h"

int	take_max_order(t_ps_list *head)
{
	int	max_order;

	max_order = head->order;
	while (head)
	{
		if (head->order > max_order)
			max_order = head->order;
		head = head->next;
	}
	return (max_order);
}

int	take_min_order(t_ps_list *head)
{
	int	min_order;

	min_order = head->order;
	while (head)
	{
		if (head->order < min_order)
			min_order = head->order;
		head = head->next;
	}
	return (min_order);
}

int	take_next_order(t_ps_list *stack_a, int current_order, t_ps_list *check)
{
	int	next_order;
	int	diff;

	diff = ps_lstsize(check);
	next_order = stack_a->order;
	while (stack_a)
	{
		if (stack_a->order - current_order > 0
			&& stack_a->order - current_order < diff)
		{
			diff = stack_a->order - current_order;
			next_order = stack_a->order;
		}
		stack_a = stack_a->next;
	}
	return (next_order);
}

int	find_min_move_order(t_ps_list *head)
{
	t_ps_list	*tmp;
	int			min_moves;

	tmp = head;
	min_moves = tmp->moves;
	while (tmp)
	{
		if (tmp->moves < min_moves)
			min_moves = tmp->moves;
		tmp = tmp->next;
	}
	while (head)
	{
		if (min_moves == head->moves)
			break ;
		head = head->next;
	}
	return (head->order);
}

void	fill_stack_order(t_ps_list *stack_a, t_ps_list *check)
{
	t_ps_list	*tmp;

	while (check)
	{
		tmp = stack_a;
		while (tmp)
		{
			if (check->value == tmp->value)
				tmp->order = check->order;
			tmp = tmp->next;
		}
		check = check->next;
	}
}
