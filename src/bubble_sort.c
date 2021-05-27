#include "../includes/push_swap.h"

static void	placing_order(t_ps_list *head)
{
	t_ps_list	*tmp;
	int			i;

	i = 1;
	tmp = head;
	while (tmp)
	{
		tmp->order = i;
		tmp = tmp->next;
		i++;
	}
}

void	bubble_sort(t_ps_list *head, int size)
{
	int			i;
	int			j;
	int			temp_value;
	t_ps_list	*tmp_j;

	i = 0;
	while (i < size)
	{
		j = 0;
		tmp_j = head;
		while (j < size - i - 1)
		{
			if (tmp_j->value > tmp_j->next->value)
			{
				temp_value = tmp_j->next->value;
				tmp_j->next->value = tmp_j->value;
				tmp_j->value = temp_value;
			}
			j++;
			tmp_j = tmp_j->next;
		}
		i++;
	}
	placing_order(head);
}
