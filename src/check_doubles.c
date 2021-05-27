#include "../includes/push_swap.h"

void	check_doubles(t_ps_list *head)
{
	t_ps_list	*tmp;

	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->value != tmp->value)
				tmp = tmp->next;
			else
				error_message();
		}
		head = head->next;
	}
}
