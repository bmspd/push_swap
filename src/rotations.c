#include "../includes/push_swap.h"

static void	reverse_move(t_ps_list **stack_a, t_ps_list *tmp)
{
	int	n;
	int	i;

	i = 0;
	n = ps_lstsize(tmp);
	while (i < n)
	{
		reverse_rotate_a(stack_a);
		i++;
	}
}

static void	normal_move(t_ps_list **stack_a, t_ps_list *tmp)
{
	int	n;
	int	i;

	i = 0;
	n = ps_lstsize(*stack_a) - ps_lstsize(tmp);
	while (i < n)
	{
		rotate_a(stack_a);
		i++;
	}
}

void	make_rotations(t_ps_list **stack_a, int order)
{
	t_ps_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->order == order)
			break ;
		tmp = tmp->next;
	}
	if (ps_lstsize(*stack_a) - ps_lstsize(tmp) > ps_lstsize(*stack_a) / 2)
		reverse_move(stack_a, tmp);
	else
		normal_move(stack_a, tmp);
}

void	up_or_down_move(t_ps_list **stack_b, t_ps_list *current)
{
	int	i;
	int	n;

	i = 0;
	if (ps_lstsize(*stack_b) - ps_lstsize(current) > ps_lstsize(*stack_b) / 2)
	{
		n = ps_lstsize(current);
		while (i < n)
		{
			reverse_rotate_b(stack_b);
			i++;
		}
	}
	else
	{
		n = ps_lstsize(*stack_b) - ps_lstsize(current);
		while (i < n)
		{
			rotate_b(stack_b);
			i++;
		}
	}
}

void	make_moves(t_ps_list **stack_a, t_ps_list **stack_b,
				int order, t_ps_list *check)
{
	t_ps_list	*head;

	head = *stack_b;
	while (head)
	{
		if (head->order == order)
			break ;
		head = head->next;
	}
	up_or_down_move(stack_b, head);
	if (head->order > take_max_order(*stack_a))
	{
		make_rotations(stack_a, take_max_order(*stack_a));
		rotate_a(stack_a);
	}
	else if (head->order < take_min_order(*stack_a))
	{
		make_rotations(stack_a, take_min_order(*stack_a));
	}
	else
	{
		make_rotations(stack_a, take_next_order(*stack_a, head->order, check));
	}
	push_a(stack_b, stack_a);
}
