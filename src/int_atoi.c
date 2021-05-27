#include "../includes/push_swap.h"

static int	tabpass(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		   || str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

//-2147483648 int min
//2147483647 int max

int	check_overflow(unsigned long nbr, char c, int sign)
{
	unsigned long	overflow;

	overflow = 214748364;
	if ((nbr > overflow || (nbr == overflow
				&& c > '7')) && sign == 1)
		return (error_message());
	if ((nbr > overflow || (nbr == overflow
				 && c > '8')) && sign == -1)
		return (error_message());
	return (0);
}

int	int_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nbr;

	nbr = 0;
	sign = 1;
	i = tabpass(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		error_message();
	while (str[i] >= '0' && str[i] <= '9')
	{
		check_overflow(nbr, str[i], sign);
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return ((int)nbr * sign);
}
