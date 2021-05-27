#include "../includes/push_swap.h"

void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*tmp;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			new->prev = tmp;
			tmp->next = new;
		}
	}
}
