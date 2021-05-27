#include "../includes/push_swap.h"

void	ps_lstadd_front(t_ps_list **lst, t_ps_list *new)
{
	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
}
