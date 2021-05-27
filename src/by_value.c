#include "../includes/push_swap.h"

int	elements_increased_by_value(t_ps_list *head)
{
	int	value;
	int	count;

	count = 1;
	value = head->value;
	while (head)
	{
		if (head->value > value)
		{
			value = head->value;
			count++;
		}
		head = head->next;
	}
	return (count);
}

int	take_best_case_by_value(t_ps_list *head)
{
	int	needed_order;
	int	value;

	value = elements_increased_by_value(head);
	needed_order = head->order;
	while (head)
	{
		if (value < elements_increased_by_value(head))
		{
			value = elements_increased_by_value(head);
			needed_order = head->order;
		}
		head = head->next;
	}
	return (needed_order);
}

void	fill_value_flags(t_ps_list *head, int best_case_order)
{
	t_ps_list	*tmp;
	int			value;

	tmp = head;
	while (tmp)
	{
		if (tmp->order == best_case_order)
			value = tmp->value;
		tmp = tmp->next;
	}
	while (head)
	{
		if (head->value >= value && head->order >= best_case_order)
		{
			head->flag = 1;
			value = head->value;
		}
		head = head->next;
	}
}

int	take_by_value_amount(t_ps_list *stack_a)
{
	int	amount;

	amount = elements_increased_by_value(stack_a);
	while (stack_a)
	{
		if (amount < elements_increased_by_value(stack_a))
			amount = elements_increased_by_value(stack_a);
		stack_a = stack_a->next;
	}
	return (amount);
}
