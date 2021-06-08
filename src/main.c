#include "../includes/push_swap.h"

int	check_zero_flag(t_ps_list *head)
{
	while (head)
	{
		if (head->flag == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

void	fill_flags_best_scenario(t_ps_list *stack_a)
{
	int	by_index;
	int	by_value;

	by_value = take_by_value_amount(stack_a);
	by_index = take_by_index_amount(stack_a);
	if (by_value > by_index)
		fill_value_flags(stack_a, take_best_case_by_value(stack_a));
	else
		fill_flags(stack_a, take_best_case_by_index(stack_a));
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_ps_list	*check;
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		exit(0);
	split_args(&stack_a, argc, argv);
	check_doubles(stack_a);
	split_args(&check, argc, argv);
	bubble_sort(check, ps_lstsize(check));
	fill_stack_order(stack_a, check);
	if(check_is_sorted(stack_a))
		exit(0);
	if (ps_lstsize(stack_a) == 2)
		two_digits(stack_a);
	else if (ps_lstsize(stack_a) == 3)
		three_digits(&stack_a);
	else if (ps_lstsize(stack_a) == 4)
		four_digits(&stack_a, &stack_b);
	else if (ps_lstsize(stack_a) == 5)
		five_digits(&stack_a, &stack_b);
	else
		more_five_digits(&stack_a, &stack_b, check);
	exit(0);
}
