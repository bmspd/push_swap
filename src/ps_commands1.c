#include "../includes/push_swap.h"

void	swap_a(t_ps_list *head)
{
	int	tmp;

	if (ps_lstsize(head) > 1)
	{
		tmp = head->value;
		head->value = head->next->value;
		head->next->value = tmp;
		tmp = head->order;
		head->order = head->next->order;
		head->next->order = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_ps_list *head)
{
	int	tmp;

	if (ps_lstsize(head) > 1)
	{
		tmp = head->value;
		head->value = head->next->value;
		head->next->value = tmp;
		tmp = head->order;
		head->order = head->next->order;
		head->next->order = tmp;
	}
	write(1, "sb\n", 3);
}

void	push_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*tmp;
	int			order;
	int			flag;

	if (!*stack_a)
		return ;
	order = (*stack_a)->order;
	flag = (*stack_a)->flag;
	tmp = *stack_a;
	if (tmp)
		tmp = tmp->next;
	ps_lstadd_front(stack_b, ps_lstnew((*stack_a)->value));
	(*stack_b)->order = order;
	(*stack_b)->flag = flag;
	free(*stack_a);
	*stack_a = tmp;
	write(1, "pb\n", 3);
}

void	push_a(t_ps_list **stack_b, t_ps_list **stack_a)
{
	t_ps_list	*tmp;
	int			order;
	int			flag;

	if (!*stack_b)
		return ;
	order = (*stack_b)->order;
	flag = (*stack_b)->flag;
	tmp = *stack_b;
	if (tmp)
		tmp = tmp->next;
	ps_lstadd_front(stack_a, ps_lstnew((*stack_b)->value));
	(*stack_a)->order = order;
	(*stack_a)->flag = flag;
	free(*stack_b);
	*stack_b = tmp;
	write(1, "pa\n", 3);
}
