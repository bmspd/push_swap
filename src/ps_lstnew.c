#include "../includes/push_swap.h"

t_ps_list	*ps_lstnew(int value)
{
	t_ps_list	*new;

	new = (struct s_ps_list *)malloc(sizeof(t_ps_list));
	if (new)
	{
		new->value = value;
		new->order = -1;
		new->flag = 0;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}
