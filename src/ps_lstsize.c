#include "../includes/push_swap.h"

int	ps_lstsize(t_ps_list *lst)
{
	t_ps_list	*temp;
	int			i;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
