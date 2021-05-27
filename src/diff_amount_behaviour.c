#include "../includes/push_swap.h"

void	two_digits(t_ps_list *stack_a)
{
	if (stack_a->value > stack_a->next->value)
		swap_a(stack_a);
}

void	three_digits(t_ps_list **stack_a)
{
	if ((*stack_a)->order == take_min_order((*stack_a))
		&& (*stack_a)->next->order != take_max_order((*stack_a)))
		;
	else if ((*stack_a)->order == take_min_order((*stack_a))
		&& (*stack_a)->next->order == take_max_order((*stack_a)))
	{
		swap_a((*stack_a));
		rotate_a(stack_a);
	}
	else if ((*stack_a)->order != take_max_order((*stack_a))
		&& (*stack_a)->next->order == take_min_order((*stack_a)))
		swap_a((*stack_a));
	else if ((*stack_a)->order != take_min_order((*stack_a))
		&& (*stack_a)->next->order == take_max_order((*stack_a)))
		reverse_rotate_a(stack_a);
	else if ((*stack_a)->order == take_max_order((*stack_a))
		&& (*stack_a)->next->order == take_min_order((*stack_a)))
		rotate_a(stack_a);
	else
	{
		rotate_a(stack_a);
		swap_a((*stack_a));
	}
}

void	four_digits(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->order == take_min_order(*stack_a))
			break ;
		tmp = tmp->next;
	}
	make_rotations(stack_a, tmp->order);
	push_b(stack_a, stack_b);
	three_digits(stack_a);
	push_a(stack_b, stack_a);
}

void	five_digits(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->order == take_min_order(*stack_a))
			break ;
		tmp = tmp->next;
	}
	make_rotations(stack_a, tmp->order);
	push_b(stack_a, stack_b);
	four_digits(stack_a, stack_b);
	push_a(stack_b, stack_a);
}

void	more_five_digits(t_ps_list **stack_a, t_ps_list **stack_b,
					  t_ps_list *check)
{
	fill_flags_best_scenario(*stack_a);
	while (check_zero_flag(*stack_a))
	{
		if ((*stack_a)->flag == 0)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	while (*stack_b)
	{
		fill_moves(*stack_a, *stack_b, check);
		make_moves(stack_a, stack_b, find_min_move_order(*stack_b), check);
	}
	make_a_great_again(stack_a);
}
