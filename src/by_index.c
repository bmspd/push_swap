#include "../includes/push_swap.h"

int	elements_increased_by_index(t_ps_list *head)
{
	int	order;
	int	count;

	order = head->order;
	count = 1;
	while (head)
	{
		if (head->order - order == 1)
		{
			order = head->order;
			count++;
		}
		head = head->next;
	}
	return (count);
}

int	take_best_case_by_index(t_ps_list *head)
{
	int	needed_order;
	int	amount;

	amount = elements_increased_by_index(head);
	needed_order = head->order;
	while (head)
	{
		if (amount < elements_increased_by_index(head))
		{
			amount = elements_increased_by_index(head);
			needed_order = head->order;
		}
		head = head->next;
	}
	return (needed_order);
}

void	fill_flags(t_ps_list *head, int best_case_order)
{
	while (head)
	{
		if (head->order == best_case_order)
		{
			head->flag = 1;
			best_case_order++;
		}
		head = head->next;
	}
}

int	take_by_index_amount(t_ps_list *stack_a)
{
	int	amount;

	amount = elements_increased_by_index(stack_a);
	while (stack_a)
	{
		if (amount < elements_increased_by_index(stack_a))
			amount = elements_increased_by_index(stack_a);
		stack_a = stack_a->next;
	}
	return (amount);
}
