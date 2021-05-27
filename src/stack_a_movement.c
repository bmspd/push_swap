#include "../includes/push_swap.h"

static void	reversing_move(t_ps_list **stack_a, t_ps_list *current)
{
	int	i;
	int	n;

	i = 0;
	n = ps_lstsize(current);
	while (i < n)
	{
		reverse_rotate_a(stack_a);
		i++;
	}
}

static void	normal_move(t_ps_list **stack_a, t_ps_list *current)
{
	int	n;
	int	i;

	i = 0;
	n = ps_lstsize(*stack_a) - ps_lstsize(current);
	while (i < n)
	{
		rotate_a(stack_a);
		i++;
	}
}

void	make_a_great_again(t_ps_list **stack_a)
{
	int			min_order;
	t_ps_list	*current;

	min_order = take_min_order(*stack_a);
	current = *stack_a;
	while (current)
	{
		if (current->order == min_order)
			break ;
		current = current->next;
	}
	if (ps_lstsize(*stack_a) - ps_lstsize(current) > ps_lstsize(*stack_a) / 2)
		reversing_move(stack_a, current);
	else
		normal_move(stack_a, current);
}
