#include "../includes/push_swap.h"

static void	check_digits(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			error_message();
		i++;
	}
}

void	split_args(t_ps_list **head, int argc, char **argv)
{
	char	**splitted;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		splitted = ft_split(argv[i], ' ');
		while (splitted[j])
		{
			check_digits(splitted[j]);
			ps_lstadd_back(head, ps_lstnew(int_atoi(splitted[j])));
			j++;
		}
		while (j >= 0)
		{
			free(splitted[j]);
			j--;
		}
		free(splitted);
		i++;
	}
}
