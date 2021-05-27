#include "../includes/push_swap.h"

void	rotate_a(t_ps_list **stack_a)
{
	t_ps_list	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = (*stack_a);
		tmp->next->prev = tmp;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		tmp->next->next = NULL;
	}
	write(1, "ra\n", 3);
}

void	rotate_b(t_ps_list **stack_b)
{
	t_ps_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = (*stack_b);
		tmp->next->prev = tmp;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		tmp->next->next = NULL;
	}
	write(1, "rb\n", 3);
}

void	reverse_rotate_a(t_ps_list **stack_a)
{
	t_ps_list	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->next = *stack_a;
		tmp->prev = NULL;
		(*stack_a)->prev = tmp;
		*stack_a = tmp;
	}
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_ps_list **stack_b)
{
	t_ps_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->next = *stack_b;
		tmp->prev = NULL;
		(*stack_b)->prev = tmp;
		*stack_b = tmp;
	}
	write(1, "rrb\n", 4);
}
