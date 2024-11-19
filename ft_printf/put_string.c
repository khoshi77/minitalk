#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putchar_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_c(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}
